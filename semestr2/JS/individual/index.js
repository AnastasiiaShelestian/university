/** Include transactions json file that contains array of transaction objects */
const transactions = require('./transactions.json');
/** Include TransactionAnalyzer class */
const TrasnsactionAnalyzer = require('./transactionAnalyzer.js'); 

/** Initialize a TransactionAnalyzer object with transactions from transactions.json file */
const transactionAnalyzer = new TrasnsactionAnalyzer(transactions);

/** Run experiments to test all functions from TransactionAnalyzer class */
const arr = transactionAnalyzer.getAllTransactions();
console.log(arr[0]);
console.log(arr[0].toString());
console.log(transactionAnalyzer.getUniqueTransactionsTypes());
console.log(transactionAnalyzer.calculateTotalAmount());
console.log(transactionAnalyzer.calculateTotalAmountByDate(2019, undefined, 3));
console.log(transactionAnalyzer.getTransactionsByType('credit'));
console.log(transactionAnalyzer.getTransactionsInDateRange('2019-02-25', '2019-03-04'));
console.log(transactionAnalyzer.getTransactionsByMerchant('HomeDecorStoreABC'));
console.log(transactionAnalyzer.calculateAverageTransactionAmount());
console.log(transactionAnalyzer.getTransactionsByAmountRange(80, 90));
console.log(transactionAnalyzer.calculateTotalDebitAmount());
console.log(transactionAnalyzer.findMostTransactionsMonth());
console.log(transactionAnalyzer.findMostDebitTransactionMonth());
console.log(transactionAnalyzer.mostTransactionsType());
console.log(transactionAnalyzer.getTransactionsBeforeDate('2019-01-05'));
console.log(transactionAnalyzer.findTransactionById(36));
console.log(transactionAnalyzer.mapTransactionDescriptions());