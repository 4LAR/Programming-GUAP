// д
db.Sight.aggregate([
  {
    $group: {
      _id: null,
      minDate: { $min: "$create_date" }
    }
  },
  {
    $project: {
      _id: 0,
      minDate: 1
    }
  },
  {
    $lookup: {
      from: "Sight",
      localField: "minDate",
      foreignField: "create_date",
      as: "oldest_sights"
    }
  },
  {
    $unwind: "$oldest_sights"
  },
  {
    $project: {
      minDate: 1,
      sight_id: "$oldest_sights._id"
    }
  },
  {
    $lookup: {
      from: "Address",
      localField: "sight_id",
      foreignField: "list_sights",
      as: "addresses"
    }
  },
  {
    $unwind: "$addresses"
  },
  {
    $project: {
      minDate: 1,
      address_id: "$addresses._id"
    }
  },
  {
    $lookup: {
      from: "City",
      localField: "address_id",
      foreignField: "list_addr",
      as: "cities"
    }
  },
  {
    $unwind: "$cities"
  },
  {
    $project: {
      _id: 0,
      city: "$cities.city"
    }
  },
  {
    $group: {
      _id: "$city"
    }
  }
]).pretty();

//г

db.Sight.aggregate([
  {
    $match: { natural: true }
  },
  {
    $lookup: {
      from: "Address",
      localField: "_id",
      foreignField: "list_sights",
      as: "addresses"
    }
  },
  {
    $unwind: "$addresses"
  },
  {
    $lookup: {
      from: "City",
      localField: "addresses._id",
      foreignField: "list_addr",
      as: "cities"
    }
  },
  {
    $unwind: "$cities"
  },
  {
    $group: {
      _id: "$cities.city",
      natural_sights_count: { $sum: 1 }
    }
  },
  {
    $sort: { natural_sights_count: -1 }
  },
  {
    $group: {
      _id: null,
      topCity: { $first: "$_id" },
      maxCount: { $first: "$natural_sights_count" }
    }
  },
  {
    $project: {
      _id: 0,
      topCity: 1,
      maxCount: 1
    }
  }
])
