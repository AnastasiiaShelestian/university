/** Class representing an analyzer for financial transactions. */
export default class TransactionAnalyzer {
    /** An array of transaction objects */
    transactions = [];

    /**
     * Create an analyzer instance.
     * @param {Array<Object>} transactions - Array of transaction objects.
     */
    constructor(transactions) {
        transactions.forEach(element => {
            this.addTransaction(element);
        });
    }

    /**
     * Add a transaction object to the existing array of transactions stored in TransactionAnalyzer instance.
     * When adding, also add toString method to transaction object, that returns the object as string.
     * @param {Object} trasnsaction - A transaction to add to the array.
     */
    addTransaction(trasnsaction) {
        const transactionObject = {
            ...trasnsaction,
            toString: () => JSON.stringify(trasnsaction)
        };
        this.transactions.push(transactionObject);
    }

    /**
     * Get an array of all currently stored transactions.
     * @return {Array<Object>} - An array of transactions currently stored in the TransactionAnalyzer object.
     */
    getAllTransactions() {
        return this.transactions;
    }

    /**
     * Get an array of transaction types
     * @return {Array<string>} - An array of unique values for transaction types.
     */
    getUniqueTransactionsTypes() {
        const transactionTypeSet = new Set();
        this.transactions.forEach(element => {
            transactionTypeSet.add(element.transaction_type);
        });

        return Array.from(transactionTypeSet);
    }

    /**
     * Get total amount for all transactions
     * @return {number} - A sum of transaction amounts for all transactions
     */
    calculateTotalAmount() {
        let sum = 0;
        this.transactions.forEach(element => {
            sum += element.transaction_amount;
        });
        return sum;
    }

    /**
     * Get total amount for all transactions by specified date
     * If some of the arguments are not specified, the function calculates the amount by existing argiments
     * @param {number|undefined} year - The year of transactions to search for
     * @param {number|undefined} month - The month of transactions to search for
     * @param {number|undefined} day - The day of transactions to search for
     * @return {number} - A sum of transaction amounts for all transactions by specified date
     */
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
    }

    /**
     * Get an array of transactions by type specified
     * @param {string} type - The type of transactions to search by
     * @return {Array<Object>} - Array of transaction objects
     */
    getTransactionsByType(type) {
        return this.transactions.filter(element => element.transaction_type === type);
    }

    /**
     * Get an array of transactions in date range specified
     * @param {string} startDate - A string that represents the start date in format 'yyyy-mm-dd'
     * @param {string} endDate - A string that represents the end date in format 'yyyy-mm-dd'
     * @return {Array<Object>} - Array of transaction objects filtered by date that fits the range specified
     */
    getTransactionsInDateRange(startDate, endDate) {
        return this.transactions.filter(element => {
            const date = new Date(element.transaction_date);
            return date >= new Date(startDate) && date <= new Date(endDate);
        });
    }

    /**
     * Get an array of transactions for the merchant name specified
     * @param {string} merchantName - A string that represents the name of the merchant to search for
     * @return {Array<Object>} - Array of transaction objects filtered by merchant name specified
     */
    getTransactionsByMerchant(merchantName) {
        return this.transactions.filter(element => element.merchant_name === merchantName);
    }

    /**
     * Get average amount for all transactions
     * @return {number} - The average amount for all transactions 
    */
    calculateAverageTransactionAmount() {
        return this.calculateTotalAmount() / this.transactions.length;
    }

    /**
     * Get array of transaction objects by amount in range specified
     * @param {number} minAmount - A minimum amount for transaction
     * @param {number} maxAmount - A maximum amount for transaction
     * @return {Array<Object>} - An array of transaction objects
    */
    getTransactionsByAmountRange(minAmount, maxAmount) {
        return this.transactions.filter(element => element.transaction_amount >= minAmount && element.transaction_amount <= maxAmount);
    }

    /**
     * Get the amount of all debit transactions
     * @return {number} - The amount of debit for all transactions
    */
    calculateTotalDebitAmount() {
        let sum = 0;
        const debitTransactions = this.getTransactionsByType('debit');
        debitTransactions.forEach(element => {
            sum += element.transaction_amount;
        });
        return sum;
    }

    /**
     * Find the number of a month in a year that has most transactions
     * @return {string} - The number of month in a year that has most transactions
    */
    findMostTransactionsMonth() {
        const set = new Set();
        this.transactions.map(element => set.add(element.transaction_date.split('-')[1]));

        let mostTransactionsMonth;
        let mostTransactions = 0;
        set.forEach(month => {
            const transactions = this.transactions.filter(element => element.transaction_date.split('-')[1] === month);
            if (transactions.length > mostTransactions) {
                mostTransactionsMonth = month;
                mostTransactions = transactions.length;
            }
        });

        return mostTransactionsMonth;
    }

    /**
     * Find the number of a month in a year that has most debit transactions
     * @return {string} - The number of month in a year that has most debit transactions
    */
    findMostDebitTransactionMonth() {
        const debitTransactions = this.getTransactionsByType('debit');
        const set = new Set();
        debitTransactions.forEach(element => set.add(element.transaction_date.split('-')[1]));

        let mostTransactionsMonth;
        let mostTransactions = 0;
        set.forEach(month => {
            const transactions = debitTransactions.filter(element => element.transaction_date.split('-')[1] === month);
            if (transactions.length > mostTransactions) {
                mostTransactionsMonth = month;
                mostTransactions = transactions.length;
            }
        });

        return mostTransactionsMonth;
    }

    /**
     * Compare the number of credit to debit transactions
     * @return {string} - A string that represents the result of comparison. 'credit' if there were more transactions with credit type;
     * 'debit' if there were more transactions with debit type; 'equal' if there is an equal amount of transactions per type.
    */
    mostTransactionsType() {
        const credit = this.getTransactionsByType('credit');
        const debit = this.getTransactionsByType('debit');
        return debit.length > credit.length ? 'debit' : credit.length > debit.length ? 'credit' : 'equal';
    }

    /**
     * Get an array of transactions that happened before the date specified
     * @param {string} date - A string that represents the date in format 'yyyy-mm-dd'
     * @return {Array<Object>} - Array of transaction objects filtered that happened before the date specified.
     */
    getTransactionsBeforeDate(date) {
        return this.transactions.filter(element => new Date(element.transaction_date) < new Date(date));
    }

    /**
     * Get a transaction by id specified
     * @param {number} id - Id of transaction
     * @return {Object} - A transaction with the id specified.
     */
    findTransactionById(id) {
        return this.transactions.find(element => element.transaction_id === id);
    }

    /**
     * Map an array of transaction descriptions
     * @return {Array<string>} - An array of desctiptions for all transactions.
     */
    mapTransactionDescriptions() {
        return this.transactions.map(element => element.transaction_description);
    }
}
