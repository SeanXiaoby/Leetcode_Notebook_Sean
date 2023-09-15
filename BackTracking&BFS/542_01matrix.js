/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function (mat) {
  const INT_MAX = 99999;
  const m = mat.length,
    n = mat[0].length;

  const queue = [];

  for (let i = 0; i < m; i++) {
    for (let j = 0; j < n; j++) {
      if (mat[i][j] === 0) {
        queue.push({ x: i, y: j });
      }
    }
  }

  const res = mat.map((row, index) => {
    return new Array(row.length).fill(INT_MAX);
  });

  const visited = mat.map((row, index) => {
    return new Array(row.length).fill(0);
  });

  while (queue.length > 0) {
    const { x, y } = queue.shift();

    if (visited[x][y] === 1) continue;
    visited[x][y] = 1;

    const adjacents = [];

    if (x + 1 < m) {
      adjacents.push({
        x: x + 1,
        y: y,
      });
    }
    if (x - 1 >= 0) {
      adjacents.push({
        x: x - 1,
        y: y,
      });
    }
    if (y + 1 < n) {
      adjacents.push({
        x: x,
        y: y + 1,
      });
    }
    if (y - 1 >= 0) {
      adjacents.push({
        x: x,
        y: y - 1,
      });
    }

    if (mat[x][y] === 0) {
      res[x][y] = 0;
    } else {
      res[x][y] =
        Math.min(res[x][y], ...adjacents.map(({ x, y }) => res[x][y])) + 1;
    }

    adjacents.forEach(({ x, y }) => {
      queue.push({ x, y });
    });
  }

  return res;
};
