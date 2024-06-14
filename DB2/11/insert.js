use sights // Переход в нужную базу данных

// Вставка города
db.createCollection("City");

db.City.insertMany([
  {
    _id: ObjectId(),
    city: "Москва",
    list_addr: []
  },
  {
    _id: ObjectId(),
    city: "Санкт-Петербург",
    list_addr: []
  },
  {
    _id: ObjectId(),
    city: "Казань",
    list_addr: []
  }
]);

// вставка адресов
db.createCollection("Address");

db.Address.insertMany([
  {
    _id: ObjectId(),
    street: "Красная площадь",
    list_sights: []
  },
  {
    _id: ObjectId(),
    street: "Арбат",
    list_sights: []
  },
  {
    _id: ObjectId(),
    street: "Невский проспект",
    list_sights: []
  },
  {
    _id: ObjectId(),
    street: "Дворцовая площадь",
    list_sights: []
  },
  {
    _id: ObjectId(),
    street: "Кремлёвская",
    list_sights: []
  },
  {
    _id: ObjectId(),
    street: "Баумана",
    list_sights: []
  }
]);

// вставка достопримечательностей
db.createCollection("Sight");

db.Sight.insertMany([
  {
    _id: ObjectId(),
    name: "Кремль",
    create_date: new Date("1156-01-01"),
    type_sight: "исторический памятник",
    natural: false,
    exhibition: false,
    house: "1"
  },
  {
    _id: ObjectId(),
    name: "Большой театр",
    create_date: new Date("1825-01-01"),
    type_sight: "театр",
    exhibition: false,
    natural: false,
    house: "10"
  },
  {
    _id: ObjectId(),
    name: "Эрмитаж",
    create_date: new Date("1764-12-07"),
    type_sight: "музей",
    exhibition: true,
    natural: false,
    house: "30"
  },
  {
    _id: ObjectId(),
    name: "Петропавловская крепость",
    create_date: new Date("1703-05-16"),
    type_sight: "крепость",
    exhibition: false,
    natural: false,
    house: "2"
  },
  {
    _id: ObjectId(),
    name: "Казанский Кремль",
    create_date: new Date("1556-01-01"),
    type_sight: "исторический памятник",
    exhibition: false,
    natural: false,
    house: "2"
  },
  {
    _id: ObjectId(),
    name: "Мечеть Кул-Шариф",
    create_date: new Date("2005-06-24"),
    type_sight: "религиозное здание",
    exhibition: false,
    natural: false,
    house: "50"
  }
]);

db.Sight.insertMany([
  {
    _id: ObjectId(),
    name: "Горький Парк",
    create_date: new Date("1928-08-12"),
    type_sight: "парк",
    exhibition: false,
    natural: true,
    house: "9"
  },
  {
    _id: ObjectId(),
    name: "Таврический сад",
    create_date: new Date("1783-01-01"),
    type_sight: "парк",
    exhibition: false,
    natural: true,
    house: "15"
  },
  {
    _id: ObjectId(),
    name: "Центральный парк культуры и отдыха",
    create_date: new Date("1931-06-01"),
    type_sight: "парк",
    exhibition: false,
    natural: true,
    house: "7"
  }
]);

db.Sight.insertMany([
  {
    _id: ObjectId(),
    name: "Родина мать",
    create_date: new Date("1931-06-01"),
    type_sight: "парк",
    exhibition: false,
    natural: true,
    house: "0"
  }
]);

// добавление ссылок

// Получение ObjectId адресов
const address1 = db.Address.findOne({ street: "Красная площадь" })._id;
const address2 = db.Address.findOne({ street: "Арбат" })._id;
const address3 = db.Address.findOne({ street: "Невский проспект" })._id;
const address4 = db.Address.findOne({ street: "Дворцовая площадь" })._id;
const address5 = db.Address.findOne({ street: "Кремлёвская" })._id;
const address6 = db.Address.findOne({ street: "Баумана" })._id;

// Обновление города Москва
db.City.updateOne(
  { city: "Москва" },
  { $push: { list_addr: { $each: [address1, address2] } } }
);

// Обновление города Санкт-Петербург
db.City.updateOne(
  { city: "Санкт-Петербург" },
  { $push: { list_addr: { $each: [address3, address4] } } }
);

// Обновление города Казань
db.City.updateOne(
  { city: "Казань" },
  { $push: { list_addr: { $each: [address5, address6] } } }
);

// Получение ObjectId достопримечательностей
const sight1 = db.Sight.findOne({ name: "Кремль" })._id;
const sight2 = db.Sight.findOne({ name: "Большой театр" })._id;
const sight3 = db.Sight.findOne({ name: "Эрмитаж" })._id;
const sight4 = db.Sight.findOne({ name: "Петропавловская крепость" })._id;
const sight5 = db.Sight.findOne({ name: "Казанский Кремль" })._id;
const sight6 = db.Sight.findOne({ name: "Мечеть Кул-Шариф" })._id;
const sight7 = db.Sight.findOne({ name: "Родина мать" })._id;

// Обновление адреса Красная площадь
db.Address.updateOne(
  { street: "Красная площадь" },
  { $push: { list_sights: sight1 } }
);

db.Address.updateOne(
  { street: "Красная площадь" },
  { $push: { list_sights: sight7 } }
);

// Обновление адреса Арбат
db.Address.updateOne(
  { street: "Арбат" },
  { $push: { list_sights: sight2 } }
);

// Обновление адреса Невский проспект
db.Address.updateOne(
  { street: "Невский проспект" },
  { $push: { list_sights: sight3 } }
);

// Обновление адреса Дворцовая площадь
db.Address.updateOne(
  { street: "Дворцовая площадь" },
  { $push: { list_sights: sight4 } }
);

// Обновление адреса Кремлёвская
db.Address.updateOne(
  { street: "Кремлёвская" },
  { $push: { list_sights: sight5 } }
);

// Обновление адреса Баумана
db.Address.updateOne(
  { street: "Баумана" },
  { $push: { list_sights: sight6 } }
);

// Получение ObjectId парков
const park1 = db.Sight.findOne({ name: "Горький Парк" })._id;
const park2 = db.Sight.findOne({ name: "Таврический сад" })._id;
const park3 = db.Sight.findOne({ name: "Центральный парк культуры и отдыха" })._id;

// Обновление адреса Красная площадь
db.Address.updateOne(
  { street: "Красная площадь" },
  { $push: { list_sights: park1 } }
);

// Обновление адреса Невский проспект
db.Address.updateOne(
  { street: "Невский проспект" },
  { $push: { list_sights: park2 } }
);

// Обновление адреса Баумана
db.Address.updateOne(
  { street: "Баумана" },
  { $push: { list_sights: park3 } }
);

// Добавление выставки
db.Sight.insertOne({
  name: "Выставка 'Искусство и технологии'",
  create_date: new Date("2024-06-11"),
  type_sight: "выставка",
  exhibition: true,
  natural: false,
  house: "0"
});

db.Sight.insertOne({
  name: "Фотовыставка 'Города мира'",
  create_date: new Date("2024-07-01"),
  type_sight: "выставка",
  exhibition: true,
  natural: false,
  house: "0"
});

const exhibition = db.Sight.findOne({ name: "Выставка 'Искусство и технологии'" })._id;
const photoExhibition = db.Sight.findOne({ name: "Фотовыставка 'Города мира'" })._id;

db.Address.updateOne(
  { street: "Кремлёвская" },
  { $push: { list_sights: exhibition } }
);

db.Address.updateOne(
  { street: "Кремлёвская" },
  { $push: { list_sights: photoExhibition } }
);
