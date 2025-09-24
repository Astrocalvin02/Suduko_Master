// Simple Sudoku board logic and solver in JavaScript

const BOARD_SIZE = 9;

function createEmptyBoard() {
    return Array.from({ length: BOARD_SIZE }, () => Array(BOARD_SIZE).fill(0));
}

function isSafe(board, row, col, num) {
    for (let x = 0; x < BOARD_SIZE; x++) {
        if (board[row][x] === num || board[x][col] === num) return false;
    }
    const startRow = row - row % 3, startCol = col - col % 3;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] === num) return false;
        }
    }
    return true;
}

function solveSudoku(board) {
    for (let row = 0; row < BOARD_SIZE; row++) {
        for (let col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] === 0) {
                for (let num = 1; num <= 9; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

function renderBoard(board) {
    const boardDiv = document.getElementById('sudoku-board');
    boardDiv.innerHTML = '';
    for (let i = 0; i < BOARD_SIZE; i++) {
        for (let j = 0; j < BOARD_SIZE; j++) {
            const input = document.createElement('input');
            input.type = 'text';
            input.maxLength = 1;
            input.className = 'cell';
            input.value = board[i][j] !== 0 ? board[i][j] : '';
            input.dataset.row = i;
            input.dataset.col = j;
            input.oninput = (e) => {
                const val = parseInt(e.target.value);
                board[i][j] = (val >= 1 && val <= 9) ? val : 0;
            };
            boardDiv.appendChild(input);
        }
    }
}

function getBoardFromInputs() {
    const inputs = document.querySelectorAll('.cell');
    const board = createEmptyBoard();
    inputs.forEach(input => {
        const row = parseInt(input.dataset.row);
        const col = parseInt(input.dataset.col);
        const val = parseInt(input.value);
        board[row][col] = (val >= 1 && val <= 9) ? val : 0;
    });
    return board;
}

document.addEventListener('DOMContentLoaded', () => {
    let board = createEmptyBoard();
    renderBoard(board);

    document.getElementById('solve-btn').onclick = () => {
        board = getBoardFromInputs();
        if (solveSudoku(board)) {
            renderBoard(board);
        } else {
            alert('No solution found!');
        }
    };

    document.getElementById('reset-btn').onclick = () => {
        board = createEmptyBoard();
        renderBoard(board);
    };
});
