
const auth_menu_items = [
  ["login", "Authorization"],
  ["register", "Register"],
  ["register_code", "Register"],
  ["reset", "Reset password"],
  ["reset_code", "Reset password"]
]

var current_menu_item = "";
function change_auth_menu(selected_item) {
  for (const item of auth_menu_items) {
    if (item[0] == selected_item) {
      current_menu_item = item[0];
      document.getElementById('page_name').innerHTML = item[1];
      document.getElementById(`${item[0]}_container`).style.display = "block";
    } else {
      document.getElementById(`${item[0]}_container`).style.display = "none";
    }
  }
  if (selected_item == auth_menu_items[0][0]) {
    document.getElementById('back_menu').style.display = "none";
    document.getElementById('page_name').style.marginLeft = "10px";
  } else {
    document.getElementById('back_menu').style.display = "block";
    document.getElementById('page_name').style.marginLeft = "50px";
  }
  remove_inputs_error();
}

function back_auth_menu() {
  switch (current_menu_item) {
    case auth_menu_items[1][0]: // register
      change_auth_menu(auth_menu_items[0][0])
      break;
    case auth_menu_items[2][0]: // register_code
      change_auth_menu(auth_menu_items[1][0])
      break;
    case auth_menu_items[3][0]: // reset
      change_auth_menu(auth_menu_items[0][0])
      break;
    case auth_menu_items[4][0]: // reset_code
      change_auth_menu(auth_menu_items[3][0])
      break;
    default:
      break;
  }
}

change_auth_menu("login")
