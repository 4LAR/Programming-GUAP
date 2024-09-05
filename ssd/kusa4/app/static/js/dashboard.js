
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

function get_audit() {
  fetch('/checkpoint/get_audit', {
    method: 'POST',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    }
  })
  .then(response => {
    response.json().then(data => {
      console.log(data);
      clear_ul("audit");
      for (const user of data.audit) {
        append_to_ul("audit", `
          <div class="inline">
            <h2>${user["datetime"]} | ${user["token"]} | ${user["user"]}</h2>
          </div>
        `)
      }
    });
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

const getAuditPdf = async () => {
  var date = document.getElementById('audit_date').value;
  const response = await fetch(`/checkpoint/get_audit_pdf?date_str=${date}`, {
    method: 'GET',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    }
  });

  if (!response.ok) {
    const error = await response.json();
    console.error('Error:', error.detail);
  } else {
    const blob = await response.blob();
    const url = window.URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'audit_report.pdf'; // Имя файла для скачивания
    document.body.appendChild(a);
    a.click();
    a.remove();
  }
};

// -----------------------------------------------------------------------------

function get_cards() {
  fetch('/checkpoint/card_list', {
    method: 'POST',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    }
  })
  .then(response => {
    response.json().then(data => {
      console.log(data);
      clear_ul("cards");
      for (const user of data.cards) {
        append_to_ul("cards", `
          <div class="inline">
            <h2>${user["id"]} | ${user["name"]} | ${user["token"]}</h2>
          </div>
        `)
      }
    });
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

function add_card() {
  fetch('/checkpoint/add_card', {
    method: 'POST',
    headers: {
      'Authorization': `Bearer ${TOKEN}`
    },
    body: new URLSearchParams({
      name: document.getElementById("card_name").value
    })
  })
  .then(response => {
    get_cards();
  })
  .catch(error => {
    console.error('Error:', error.message);
  });
}

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
