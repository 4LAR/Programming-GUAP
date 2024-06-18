// а. достопримечательности, в которых есть слово «мать», но с него название не начинается
// Запрос на поиск подстроки
db.Sight.find({
  name: {
    $regex: "мать",
    $options: "i",
    $not: /^мать/i // Не начинается с "мать"
  }
});

// б. улица, на которой есть 2 разных вида достопримечательности
// Запрос на использование одного документа несколько раз
db.Address.aggregate([
  {
    $lookup: {
      from: "Sight",
      localField: "list_sights",
      foreignField: "_id",
      as: "sights"
    }
  },
  {
    $unwind: "$sights"
  },
  {
    $group: {
      _id: "$_id",
      street: { $first: "$street" },
      sight_types: { $addToSet: "$sights.type_sight" }
    }
  },
  {
    $match: {
      $expr: { $gte: [{ $size: "$sight_types" }, 2] }
    }
  },
  {
    $project: {
      street: 1,
      sight_types: 1
    }
  }
]);

// в. город, в котором не проводится выставок
// Запрос с условием на агрегатную функцию
db.City.aggregate([
  {
    $lookup: {
      from: "Address",
      localField: "list_addr",
      foreignField: "_id",
      as: "addresses"
    }
  },
  {
    $unwind: "$addresses"
  },
  {
    $lookup: {
      from: "Sight",
      localField: "addresses.list_sights",
      foreignField: "_id",
      as: "sights"
    }
  },
  {
    $unwind: {
      path: "$sights",
      preserveNullAndEmptyArrays: true
    }
  },
  {
    $group: {
      _id: "$_id",
      city: { $first: "$city" },
      hasExhibition: {
        $sum: {
          $cond: [{ $gt: [{ $size: { $ifNull: ["$sights.exhibitions", []] } }, 0] }, 1, 0]
        }
      }
    }
  },
  {
    $match: {
      hasExhibition: 0
    }
  }
]);

// г. местность, где больше всего природных достопримечательностей
// Запрос получением агрегатной функции от агрегатной функции
db.Address.aggregate([
  {
    $unwind: "$list_sights"
  },
  {
    $lookup: {
      from: "Sight",
      localField: "list_sights",
      foreignField: "_id",
      as: "sight_info"
    }
  },
  {
    $unwind: "$sight_info"
  },
  {
    $match: {
      "sight_info.natural": true
    }
  },
  {
    $group: {
      _id: "$_id",
      street: { $first: "$street" },
      count: { $sum: 1 }
    }
  },
  {
    $sort: { count: -1 }
  },
  {
    $limit: 1
  }
]);


// Запрос на разность 2 запросов
// запрос а
var resultA = db.Sight.find({
  name: {
    $regex: "мать",
    $options: "i",
    $not: /^мать/i
  }
}).toArray(); // Преобразуем результат в массив

// запрос б
var resultB = db.Address.aggregate([
  {
    $lookup: {
      from: "Sight",
      localField: "list_sights",
      foreignField: "_id",
      as: "sights"
    }
  },
  {
    $unwind: "$sights"
  },
  {
    $group: {
      _id: "$_id",
      street: { $first: "$street" },
      sight_types: { $addToSet: "$sights.type_sight" }
    }
  },
  {
    $match: {
      $expr: { $gte: [{ $size: "$sight_types" }, 2] }
    }
  },
  {
    $project: {
      street: 1
    }
  }
]).toArray(); // Преобразуем результат в массив

// Разность результатов
var difference = resultA.filter(docA => !resultB.some(docB => docB.street === docA.name)); // Здесь используем имя улицы для сравнения

// д. города с самыми старыми достопримечательностями
db.City.aggregate([
  {
    $lookup: {
      from: "Address",
      localField: "list_addr",
      foreignField: "_id",
      as: "addresses"
    }
  },
  {
    $unwind: "$addresses"
  },
  {
    $lookup: {
      from: "Sight",
      localField: "addresses.list_sights",
      foreignField: "_id",
      as: "sights"
    }
  },
  {
    $unwind: "$sights"
  },
  {
    $sort: { "sights.create_date": 1 } // Сортируем достопримечательности по возрастанию даты создания
  },
  {
    $group: {
      _id: "$_id",
      city: { $first: "$city" },
      oldest_sight: { $first: "$sights" } // Берем самую старую достопримечательность для каждого города
    }
  },
  {
    $project: {
      _id: 0,
      city: 1,
      oldest_sight: {
        name: 1,
        create_date: 1
      }
    }
  },
  {
    $sort: { "oldest_sight.create_date": 1 } // Сортируем города по возрастанию даты создания достопримечательности
  },
  {
    $limit: 1 // Получаем только один город с самой старой достопримечательностью
  }
]);
