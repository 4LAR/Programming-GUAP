var app = angular.module('Fridge', []);

app.controller("FridgeController", function ($scope, $http) {

    $scope.successGetFridgsCallback = function (response) {
         $scope.FridgeList = response.data;
        $scope.errormessage="";
    };

    $scope.errorGetFridgsCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to get list of Fridge";
    };

    $scope.getFridge = function () {
        $http.get('/public/rest/Fridge').then($scope.successGetFridgsCallback, $scope.errorGetFridgsCallback);
    };

    $scope.successDeleteFridgeCallback = function (response) {
        for (var i = 0; i < $scope.FridgeList.length; i++) {
            var j = $scope.FridgeList[i];
            if (j.id === $scope.deletedId) {
                $scope.FridgeList.splice(i, 1);
                break;
            }
        }
        $scope.errormessage="";
    };

    $scope.errorDeleteFridgeCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to delete Fridge; check if there are any related records exist. Such records should be removed first";
    };

    $scope.deleteFridge = function (id) {
        $scope.deletedId = id;
        $http.delete('/public/rest/Fridge/' + id).then($scope.successDeleteFridgeCallback, $scope.errorDeleteFridgeCallback);
    };


    $scope.successGetFridgeCallback = function (response) {
        console.log(response.data);
        $scope.FridgeList.splice(0, 0, response.data);
        // $scope.FridgeList.push(response.data);
        $scope.errormessage="";
    };

    $scope.errorGetFridgeCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to get information on Fridge number " + $scope.inputnumber;
    };

    $scope.successAddFridgeCallback = function (response) {
        $http.get('/public/rest/Fridge/' + $scope.inputname).then($scope.successGetFridgeCallback, $scope.errorGetFridgeCallback);
        $scope.errormessage="";
    };

    $scope.errorAddFridgeCallback = function (error) {
        console.log(error);
        $scope.errormessage="Impossible to add new Fridge; check if it's number is unique";
    };

    $scope.addFridge = function () {
        $http.post('/public/rest/Fridge/' + $scope.inputnumber + "/" + $scope.inputname + "/" + $scope.inputtime).then($scope.successAddFridgeCallback, $scope.errorAddFridgeCallback);
    };

});
