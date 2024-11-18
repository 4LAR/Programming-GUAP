// Вставка городо
db.City.insertMany([
  { _id: ObjectId(), city: "Москва", list_addr: [] },
  { _id: ObjectId(), city: "Санкт-Петербург", list_addr: [] },
  { _id: ObjectId(), city: "Казань", list_addr: [] }
]);

// Удаление города
db.City.deleteOne({ city: "Казань" });
