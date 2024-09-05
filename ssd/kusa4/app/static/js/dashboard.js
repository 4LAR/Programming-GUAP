
const menu_pages = [
  "cameras",
  "users",
  "audit",
  "cards"
]

function open_main_menu(page) {
  for (el of menu_pages) {
    if (page === el) {
      document.getElementById(`main_container_${el}`).style.display = "block";
    } else {
      document.getElementById(`main_container_${el}`).style.display = "none";
    }
  }
}

open_main_menu(menu_pages[0]);

// -----------------------------------------------------------------------------

function remove_user(user) {
  fetch('/auth/remove_user', {
    method: 'POST',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    },
    body: new URLSearchParams({
      login: user
    })
  })
  .then(response => {
    get_users();
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

function add_user() {
  fetch('/auth/add_user', {
    method: 'POST',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    },
    body: new URLSearchParams({
      login: document.getElementById("user_login").value,
      password: document.getElementById("user_password").value,
      role: document.getElementById("user_role").value
    })
  })
  .then(response => {
    get_users();
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

function get_users() {
  fetch('/auth/get_users', {
    method: 'POST',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    }
  })
  .then(response => {
    response.json().then(data => {
      console.log(data);
      clear_ul("users");
      for (const user of data) {
        append_to_ul("users", `
          <div class="inline">
            <button type="button" onclick="remove_user('${user["login"]}')">
              Удалить
            </button>
            <h2>${user["login"]} | ${user["role"]}</h2>
          </div>
        `)
      }
    });
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
