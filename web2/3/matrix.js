var symbol = 7;

function fillMatrix(n) {
  let matrix = [];
  for (let i = 0; i < n; i++) {
    matrix[i] = new Array(n).fill(0);
  }
  for (let i = 0; i < n; i++) {
    for (let j = 0; j <= i - 1; j++) {
      matrix[i][j] = symbol;
      matrix[i][n - 1 - j] = symbol;
    }
  }

  return matrix;
}

let size = Number(document.getElementById('size').value);
var resultMatrix = fillMatrix(size);
result = '';
for (let i = 0; i < size; i++) {
  result += resultMatrix[i].join(' ')+'\n';
}
document.getElementById('myrezult').value = result;
