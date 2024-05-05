


function get_month() {
  const currentMonthNumber = new Date().getMonth();
  const monthNames = [
    'январь', 'февраль', 'март', 'апрель', 'май', 'июнь',
    'июль', 'август', 'сентябрь', 'октябрь', 'ноябрь', 'декабрь'
  ];
  return monthNames[currentMonthNumber];
}

document.addEventListener("DOMContentLoaded", () => document.getElementById('date').innerHTML = `Сегодня ${get_month().toUpperCase()}!`);
