# Индивидуальная работа №1
**Цель**: Изучить основные функции и синтаксис JavaScript на основе консольного приложения для
анализа транзакций.

## Инструкции по запуску проекта
- Установить `Node.js`
- Поместить файл `transaction.json`, в котором находятся данные о транзакциях, в директорию с файлом `main.js`
- Убедиться, что в файле `main.js` правильно указан путь к данным с транзакциями

## Описание индивидуальной работы
Суть работы заключается в том, чтобы разработать консольное приложение, способное проводить анализ финансовых транзакций, предоставленных в виде файла, с целью выявления различных статистических данных. (расчет общей суммы всех транзакций, среднего значения транзакций и т.д.).

## Краткая документация к проекту
В проекте ключевую роль играет класс TransactionAnalyzer, поскольку он ответственен за обработку данных, содержащихся в отдельном файле. В этом классе реализованы методы для анализа транзакций, о которых будет рассказано далее.

```javascript

constructor(transactions)

addTransaction(trasnsaction) - Add a transaction object to the existing array of transactions stored in TransactionAnalyzer instance.

getAllTransactions() - An array of transactions currently stored in the TransactionAnalyzer object.

getUniqueTransactionsTypes() - An array of unique values for transaction types.

calculateTotalAmount() - A sum of transaction amounts for all transactions.

calculateTotalAmountByDate(year, month, day) - A sum of transaction amounts for all transactions by specified date.

getTransactionsByType(type) - Array of transaction objects.

getTransactionsInDateRange(startDate, endDate)  - Array of transaction objects filtered by date that fits the range specified.

getTransactionsByMerchant(merchantName) - Array of transaction objects filtered by merchant name specified.

calculateAverageTransactionAmount() - The average amount for all transactions.

getTransactionsByAmountRange(minAmount, maxAmount) - An array of transaction objects.

calculateTotalDebitAmount() - The amount of debit for all transactions.

findMostTransactionsMonth() - The number of month in a year that has most transaction.

findMostDebitTransactionMonth() - The number of month in a year that has most debit transactions.

mostTransactionsType() - A string that represents the result of comparison. 'credit' if there were more transactions with credit type;

getTransactionsBeforeDate(date) - Array of transaction objects filtered that happened before the date specified.

findTransactionById(id) - A transaction with the id specified.

mapTransactionDescriptions() - An array of desctiptions for all transactions.

```

## Пexamples of project use:
Find the number of a month in a year that has most debit transactions.
```javascript

 findMostDebitTransactionMonth() {
        const debitTransactions = this.getTransactionsByType('debit');
        const set = new Set();
        debitTransactions.map(element => set.add(element.transaction_date.split('-')[1]));

        let mostTransactionsMonth;
        let mostTransactions = 0;
        set.forEach(month => {
            const transactions = debitTransactions.filter(element => element.transaction_date.split('-')[1] === month);
            if (transactions.length > mostTransactions) {
                mostTransactionsMonth = month;
                mostTransactions = transactions.length;
            }
        });
```
rresult in console:
```javascript
03
```

Get total amount for all transactions by specified date
If some of the arguments are not specified, the function calculates the amount by existing argiments
```javascript
calculateTotalAmountByDate(year, month, day) {
        let sum = 0;
        this.transactions.forEach(element => {
            sum += element.transaction_amount;

            const dateArray = element.transaction_date.split('-');
            if ((year && dateArray[0] != year) || (month && dateArray[1] != month) || (day && dateArray[2] != day)) {
                sum -= element.transaction_amount;
            }
        });
        return sum;
```
result in console:
```javascript
220
```
## Контрольные вопросы
**1. Какие примитивные типы данных существуют в JavaScript?**
- Строка (string)
- Число (number)
- Булево значение (boolean)
- Null
- Undefined
- Символ (symbol)
- Большое целое число (bigint)

**2. Какие методы массивов вы использовали для обработки и анализа данных в вашем приложении, и как они помогли в выполнении задачи?**
- `push` - Добавляет один или несколько элементов в конец массива.
- `find` - Находит первый элемент в массиве, соответствующий заданному условию.
- `map` - Возвращает новый массив с преобразованными элементами.
- `filter` - Оставляет в массиве только те элементы, которые соответствуют заданному условию.
- `Object.keys` - Возвращает массив ключей объекта.
- `getMonth`, `getFullYear`, `getDate` - Все эти методы используются для работы с датами, представленными объектами Date.
- `reduce` - Сводит массив к одному значению, используя заданную функцию.

**3. В чем состоит роль конструктора класса?**<br>
Роль конструктора класса заключается в том, чтобы автоматически инициализировать переменные-члены класса и обеспечить корректное начальное состояние объекта при его создании. Кроме того, конструктор может выполнять дополнительные действия, необходимые при создании объекта, такие как установка значений по умолчанию, регистрация объекта в системе, выполнение проверок или инициализация других объектов. Работа конструктора способствует повышению читаемости кода, позволяет создавать объекты с различными начальными значениями и делает код более гибким и модульным.

**4. Каким образом вы можете создать новый экземпляр класса в JavaScript?**<br>
В JavaScript существует два способа создания нового экземпляра класса: с помощью оператора `new` и с помощью функции-конструктора. В обоих случаях вызывается функция-конструктор класса, передаются необходимые аргументы в конструктор и создается новый объект с заданными свойствами. 
