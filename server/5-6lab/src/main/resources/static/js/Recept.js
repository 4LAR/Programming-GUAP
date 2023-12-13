var app = angular.module('Recept', []).config(function ($httpProvider) {
    csrftoken = $("meta[name='_csrf']").attr("content");
    csrfheader = $("meta[name='_csrf_header']").attr("content");
    $httpProvider.defaults.headers.common["X-CSRF-TOKEN"] = csrftoken;
    $(document).ajaxSend(function(e, xhr, options) {
        xhr.setRequestHeader(csrfheader, csrftoken);
    });
});

app.controller("ReceptController", function ($scope, $http) {

    $scope.successGetFridgsCallback = function (response) {
         $scope.ReceptList = response.data;
        $scope.errormessage="";
    };

    $scope.errorGetFridgsCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to get list of Recept";
    };

    $scope.getRecept = function () {
        $http.get('/public/rest/Recept').then($scope.successGetFridgsCallback, $scope.errorGetFridgsCallback);
    };

    $scope.successDeleteReceptCallback = function (response) {
        for (var i = 0; i < $scope.ReceptList.length; i++) {
            var j = $scope.ReceptList[i];
            if (j.id === $scope.deletedId) {
                $scope.ReceptList.splice(i, 1);
                break;
            }
        }
        $scope.errormessage="";
    };

    $scope.errorDeleteReceptCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to delete Recept; check if there are any related records exist. Such records should be removed first";
    };

    $scope.deleteRecept = function (id) {
        $scope.deletedId = id;
        $http.delete('/public/rest/Recept/' + id).then($scope.successDeleteReceptCallback, $scope.errorDeleteReceptCallback);
    };


    $scope.successGetReceptCallback = function (response) {
        console.log(response.data);
        $scope.ReceptList.splice(0, 0, response.data);
        // $scope.ReceptList.push(response.data);
        $scope.errormessage="";
    };

    $scope.errorGetReceptCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to get information on Recept number " + $scope.inputnumber;
    };

    $scope.successAddReceptCallback = function (response) {
        $http.get('/public/rest/Recept/' + $scope.inputname).then($scope.successGetReceptCallback, $scope.errorGetReceptCallback);
        $scope.errormessage="";
    };

    $scope.errorAddReceptCallback = function (error) {
        console.log(error);
        $scope.errormessage="Impossible to add new Recept; check if it's number is unique";
    };

    $scope.addRecept = function () {
        $http.post('/public/rest/Recept/' + $scope.inputnumber + "/" + $scope.inputname + "/" + $scope.inputrecept).then($scope.successAddReceptCallback, $scope.errorAddReceptCallback);
    };

});
