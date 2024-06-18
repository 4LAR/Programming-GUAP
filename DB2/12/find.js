// а. достопримечательности, в которых есть слово «мать», но с него название не начинается
db.Sight.find({
  name: {
    $regex: ".*мать.*",
    $options: "i"
  }
})

// б. улица, на которой есть 2 разных вида достопримечательности
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
db.Address.aggregate([
  {
    $unwind: "$list_sights" // Развернуть массив достопримечательностей
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
    $unwind: "$sight_info" // Развернуть информацию о достопримечательности
  },
  {
    $match: {
      "sight_info.natural": true // Фильтр по естественным достопримечательностям
    }
  },
  {
    $group: {
      _id: "$_id",
      street: { $first: "$street" },
      count: { $sum: 1 } // Подсчёт количества природных достопримечательностей на улице
    }
  },
  {
    $sort: { count: -1 } // Сортировка по убыванию количества природных достопримечательностей
  },
  {
    $limit: 1 // Получить только одну местность с наибольшим количеством природных достопримечательностей
  }
]);

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
