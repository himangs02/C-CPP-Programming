<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>CALCULATOR</title>
    <link rel="stylesheet" href="calculator.css">
    <style>
        .container{
            display: flex;
            justify-content: center;
            position: relative;
        }
        body{
            background-color:#b39cd0;
        }
        #a{
            display: grid;
            grid-template-columns: repeat(3, 1fr);
            gap: 30px; 
            padding: 20px;
            text-align: center;
            position: relative;
            top: 250px;
            left: 250px;
        }
        #a button{
            border: none;
            border-radius: 100px;
            font-size: 60px;
        }
        #a button:hover{
            background-color:#fbeaff;
        }
        #b{
            display: grid;
            grid-template-columns: repeat(5,1fr);
            padding: 60px;
            gap:6px;
            position: relative;
            height: 50px;
            top: 140px;
            right: 110px;
        }
        #b button{
            border: none;
            border-radius: 15px;
            font-size: 25px;
        }
        #b button:hover{
            background-color: #fbeaff;
        }
        #c{
            display: grid;
            grid-template-rows: repeat(4,1fr);
            position: relative;
            top: 260px;
            right: 150px;
            border: none;
            gap: 10px;
            height: 380px;
            width: 45px;
        }
        #c button{
            border: none;
            border-radius: 10px;
            font-size: 25px;
        }
        #c button:hover{
            background-color: #fbeaff;
        }
        #d{
            display: grid;
            grid-template-columns: repeat(2,1fr);
            position: relative;
            right:650px;
            top: 280px;
            gap: 10px;
            height: 350px;
        }
        #d button{
            font-size: 25px;
            border: none;
            border-radius: 20px;
        }
        #d button:hover{
            background-color:#fbeaff;
        }
        .box{
            display: flex;
            justify-content: center;
            position: relative;
            bottom:290px;
            font-size: 1000px;
            height: 50px;
            border: none;
            background-color: #b39cd0;
        }
        #display-container {
            display: flex;
            justify-content: center;
            position: relative;
            top: 220px;
        }
        #display {
            width: 80%;
            height: 50px;
            font-size: 40px;
            text-align: right;
            padding: 10px;
            border: 2px solid #000;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }
        #clear-button {
            display: flex;
            justify-content: center;
            position: relative;
            top: 230px;
        }
        #clear-button button {
            font-size: 25px;
            border: none;
            border-radius: 20px;
            padding: 10px 20px;
            background-color: #ff6b6b;
            color: white;
        }
        #clear-button button:hover {
            background-color: #ff4c4c;
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="a">
            <button onclick="appendNumber('1')">1</button>
            <button onclick="appendNumber('2')">2</button>
            <button onclick="appendNumber('3')">3</button>
            <button onclick="appendNumber('4')">4</button>
            <button onclick="appendNumber('5')">5</button>
            <button onclick="appendNumber('6')">6</button>
            <button onclick="appendNumber('7')">7</button>
            <button onclick="appendNumber('8')">8</button>
            <button onclick="appendNumber('9')">9</button>
            <button onclick="appendNumber('00')">00</button>
            <button onclick="appendNumber('0')">0</button>
            <button onclick="appendNumber('.')">.</button>
        </div>
        <div id="b">
            <button onclick="setFunction('sin')">sin</button>
            <button onclick="setFunction('cos')">cos</button>
            <button onclick="setFunction('tan')">tan</button>
            <button onclick="setFunction('rad')">rad</button>
            <button onclick="setFunction('deg')">deg</button>
        </div>
        <div id="c">
            <button onclick="appendOperator('X')">X</button>
            <button onclick="appendOperator('-')">-</button>
            <button onclick="appendOperator('+')">+</button>
            <button onclick="calculate()">=</button>
        </div>
        <div id="d">
            <button onclick="setFunction('log')">log</button>
            <button onclick="setFunction('inv')">inv</button>
            <button onclick="appendOperator('/')">/</button>
            <button onclick="setFunction('factorial')">!</button>
            <button onclick="appendOperator('^')">^</button>
            <button><img src="" alt=""></button>
            <button><img src="" alt=""></button>
            <button onclick="appendOperator('e')">e</button>
        </div>
    </div>
    <div class="box">
        <input type="text" id="display" readonly>
    </div>
    <div id="clear-button">
        <button onclick="clearDisplay()">C</button>
    </div>
    <script>
        let display = document.getElementById('display');
        let currentValue = '';
        let currentFunction = '';
        
        function appendNumber(number) {
            currentValue += number;
            display.value = currentValue;
        }
        
        function appendOperator(operator) {
            currentValue += ' ' + operator + ' ';
            display.value = currentValue;
        }
        
        function setFunction(func) {
            currentFunction = func;
            calculate();
        }
        
        function calculate() {
            if (currentFunction === 'sin') {
                display.value = Math.sin(parseFloat(currentValue));
            } else if (currentFunction === 'cos') {
                display.value = Math.cos(parseFloat(currentValue));
            } else if (currentFunction === 'tan') {
                display.value = Math.tan(parseFloat(currentValue));
            } else if (currentFunction === 'rad') {
                display.value = parseFloat(currentValue) * (Math.PI / 180);
            } else if (currentFunction === 'deg') {
                display.value = parseFloat(currentValue) * (180 / Math.PI);
            } else if (currentFunction === 'log') {
                display.value = Math.log10(parseFloat(currentValue));
            } else if (currentFunction === 'inv') {
                display.value = 1 / parseFloat(currentValue);
            } else if (currentFunction === 'factorial') {
                display.value = factorial(parseInt(currentValue));
            } else {
                try {
                    display.value = eval(currentValue.replace('X', '*').replace('^', '**'));
                } catch (e) {
                    display.value = 'Error';
                }
            }
            currentValue = '';
            currentFunction = '';
        }
        
        function factorial(n) {
            if (n === 0) {
                return 1;
            }
            return n * factorial(n - 1);
        }

        function clearDisplay() {
            currentValue = '';
            display.value = '';
        }
    </script>
</body>
</html>
