
var USER = {};
var TOKEN = "";

/* -------------------------------------------------------------------------- */

var form_error = document.getElementById('error_prompt');

function show_error_prompt(prompt) {
  form_error.innerHTML = prompt;
  form_error.style.display = "block";
}

function close_error_prompt() {
  form_error.style.display = "none";
}

function remove_error(el) {
  if (el.className == "input_style error") {
    el.className = "input_style";
  }
}

close_error_prompt();

/* -------------------------------------------------------------------------- */

function remove_inputs_error() {
  for (const input of [
    document.getElementById('login_login'),
    document.getElementById('login_password'),
    document.getElementById('register_name'),
    document.getElementById('register_email'),
    document.getElementById('register_password'),
    document.getElementById('register_repeat_password'),
    document.getElementById('register_code'),
    document.getElementById('reset_email'),
    document.getElementById('reset_password'),
    document.getElementById('reset_repeat_password'),
    document.getElementById('reset_code')
  ]) {
    input.className = "input_style";
  }
  close_error_prompt();
}

/* -------------------------------------------------------------------------- */

function login_request(button) {
  if (button.className == "loading")
    return;

  button.className = "loading";
  close_error_prompt();
  var login = document.getElementById('login_login');
  var password = document.getElementById('login_password');

  // Проверки
  var error_flag = false;
  if (login.value.length < 1) {
    login.className = "input_style error";
    error_flag = true;
  }

  if (password.value.length < 1) {
    password.className = "input_style error";
    error_flag = true;
  }

  if (error_flag) {
    show_error_prompt('These fields cannot be empty');
    button.className = "";
    return;
  }

  // Запрос
  return fetch('/auth/login', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      login: login.value,
      password: password.value,
    }),
  })
  .then(response => {
    if (response.ok) {
      response.json().then(data => {
        localStorage.setItem('token', data.token);
        get_data(
          function() {button.className = ""}
        );
      });
    } else {
      response.json().then(errorData => {
        show_error_prompt(errorData.detail);
        button.className = "";
      });
    }
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

function login_func(login, password, onload=undefined) {
  // Запрос
  return fetch('/auth/login', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      login: login,
      password: password,
    }),
  })
  .then(response => {
    response.json().then(data => {
      localStorage.setItem('token', data.token);
      get_data(onload);
    });
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

/* -------------------------------------------------------------------------- */

var register_password = "";
function register_request(button) {
  if (button.className == "loading")
    return;

  button.className = "loading";
  close_error_prompt();
  var name = document.getElementById('register_name');
  var email = document.getElementById('register_email');
  var password = document.getElementById('register_password');
  register_password = password.value;
  var repeat_password = document.getElementById('register_repeat_password');

  // Проверка: Заполнение полей
  var error_length_flag = false;
  for (const el of [name, email, password, repeat_password]) {
    if (el.value.length < 1) {
      el.className = "input_style error";
      error_length_flag = true;
    }
  }

  if (error_length_flag) {
    show_error_prompt('These fields cannot be empty');
    button.className = "";
    return;
  }

  // проверка: схожесть паролей
  if (password.value !== repeat_password.value) {
    show_error_prompt("passwords don't match");
    button.className = "";
    return;
  }

  // Запрос
  return fetch('/auth/register', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      name: name.value,
      email: email.value,
      password: password.value
    }),
  })
  .then(response => {
    if (response.ok) {
      button.className = "";
      document.getElementById('register_email_send').innerHTML = `The confirmation code was sent to: ${email.value}`;
      change_auth_menu("register_code");
    } else {
      response.json().then(errorData => {
        show_error_prompt(errorData.detail);
        button.className = "";
      });
    }
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

/* -------------------------------------------------------------------------- */

function register_code_request(button) {
  if (button.className == "loading")
    return;

  button.className = "loading";
  close_error_prompt();
  var register_code = document.getElementById('register_code');
  var email = document.getElementById('register_email');

  // Проверка: Заполнение полей
  if (email.value.length < 1) {
    email.className = "input_style error";
    show_error_prompt('These fields cannot be empty');
    return;
  }

  // Запрос
  return fetch('/auth/check_code', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      login: email.value,
      code: register_code.value
    }),
  })
  .then(response => {
    if (response.ok) {
      login_func(
        email.value,
        register_password,
        function() {button.className = ""}
      );
    } else {
      response.json().then(errorData => {
        show_error_prompt(errorData.detail);
        button.className = "";
      });
    }
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

/* -------------------------------------------------------------------------- */

function reset_request(button) {
  if (button.className == "loading")
    return;

  button.className = "loading";
  close_error_prompt();
  var email = document.getElementById('reset_email');

  // Проверка: Заполнение полей
  if (email.value.length < 1) {
    email.className = "input_style error";
    show_error_prompt('These fields cannot be empty');
    return;
  }

  // Запрос
  return fetch('/auth/reset_password_send', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      email: email.value,
    }),
  })
  .then(response => {
    if (response.ok) {
      button.className = "";
      change_auth_menu("reset_code");
    } else {
      response.json().then(errorData => {
        show_error_prompt(errorData.detail);
        button.className = "";
      });
    }
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

/* -------------------------------------------------------------------------- */

function reset_code_request(button) {
  if (button.className == "loading")
    return;

  button.className = "loading";
  close_error_prompt();
  var email = document.getElementById('reset_email');
  var code = document.getElementById('reset_code');
  var password = document.getElementById('reset_password');
  var repeat_password = document.getElementById('reset_repeat_password');

  // Проверка: Заполнение полей
  var error_length_flag = false;
  for (const el of [code, password, repeat_password]) {
    if (el.value.length < 1) {
      el.className = "input_style error";
      error_length_flag = true;
    }
  }

  if (error_length_flag) {
    show_error_prompt('These fields cannot be empty');
    button.className = "";
    return;
  }

  // проверка: схожесть паролей
  if (password.value !== repeat_password.value) {
    show_error_prompt("passwords don't match");
    button.className = "";
    return;
  }

  // Запрос
  return fetch('/auth/reset_password', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/x-www-form-urlencoded',
    },
    body: new URLSearchParams({
      email: email.value,
      code: code.value,
      password: password.value
    }),
  })
  .then(response => {
    if (response.ok) {
      login_func(
        email.value,
        password.value,
        function() {button.className = ""}
      );
    } else {
      response.json().then(errorData => {
        show_error_prompt(errorData.detail);
        button.className = "";
      });
    }
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

/* -------------------------------------------------------------------------- */

function open_main_container() {
  if (!!get_localStorage("token")) {
    document.getElementById("auth_container").style.display = "none";
    document.getElementById("dashboard_container").style.display = "block";
  } else {
    document.getElementById("auth_container").style.display = "block";
    document.getElementById("dashboard_container").style.display = "none";
  }
  document.getElementById("main_loading").classList.add("end");
}

function get_data(onload=undefined) {
  if (!!get_localStorage("token")) {
    TOKEN = get_localStorage("token");
    fetch('/auth/get_user', {
      method: 'POST',
      headers: {
        'Authorization': `Bearer ${TOKEN}`
      }
    })
    .then(response => {
      if (!response.ok) {
        localStorage.removeItem('token');
        TOKEN = "";
      } else {
        response.json().then(data => {
          USER = data;
          get_users();
          get_audit();
          get_cards();
        });
      }
      open_main_container();
      if (onload) onload();
    })
    .catch(error => {
      console.error('Error:', error.message);
    });
  } else {
    open_main_container();
    if (onload) onload();
  }
}

document.addEventListener("DOMContentLoaded", (event) => {
  get_data();
});
