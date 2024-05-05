document.addEventListener('DOMContentLoaded', function() {
  const form = document.getElementById('form');
  form.addEventListener('submit', function(event) {
    console.log(form.elements);
    for (const el of form.elements) {
      console.log(el.type);
      console.log(el.value.trim().length);
      if (el.value.trim().length < 1 && el.type != "button") {
        alert('Пожалуйста, заполните все обязательные поля.');
        event.preventDefault();
        break;
      }
    }
  });
});
