//
//  Набор js функций которые пригодятся в разработке
//

// открыть новую вкладку
function openInNewTab(url) {
  window.open(url, '_blank').focus();
}

// добавить элемент в список (ul)
function append_to_ul(id, content) {
  var ul = document.getElementById(id);

  var li = document.createElement("li");

  li.innerHTML = content;

  ul.appendChild(li);
}

// очистить список (ul)
function clear_ul(id) {
  document.getElementById(id).innerHTML = '';
}

// скрол до самого низа
function scroll_to_bottom(id) {
  var objDiv = document.getElementById(id);
  objDiv.scrollTop = objDiv.scrollHeight;
}

// скрол до самого верха
function scroll_to_top(id) {
  var objDiv = document.getElementById(id);
  objDiv.scrollTop = 0;
}

//
function debounce(func, wait_ms) {
  let timeout;
  return function (...args) {
    const context = this;
    clearTimeout(timeout);
    timeout = setTimeout(() => func.apply(context, args), wait_ms);
  };
}

// получить данные из локального хранилища
function get_localStorage(key, default_return=null) {
  if (localStorage.getItem(key) != null)
    return localStorage.getItem(key);

  else
    return default_return;
}

// фокус ввода на элемент
function on_focus(id) {
  document.getElementById(id).focus()
}

// генерация рандомного числа
function getRndInteger(min, max) {
  return Math.floor(Math.random() * (max - min) ) + min;
}

//
function get_arg(name) {
  const url = new URL(window.location.href);
  return url.searchParams.get(name);
}
