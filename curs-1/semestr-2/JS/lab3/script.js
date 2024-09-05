var transactions = [];

document
  .getElementById("add_transaction")
  .addEventListener("submit", addTransaction);


/**
 * The function to add transaction from "form" user input elements to the transactions array and to transactions table.
 */  
function addTransaction() {
  const id = document.getElementById("tr_id").value;
  const date = document.getElementById("tr_date").value;
  const amount = document.getElementById("tr_amount").value;
  const category = document.getElementById("tr_category").value;
  const descriprtion = document.getElementById("tr_desc").value;

  const transaction = { id, date, amount, category, descriprtion };

  transactions.push(transaction);
  const tBody = document
    .getElementById("transactions")
    .getElementsByTagName("tbody")[0];
  const newRow = tBody.insertRow(tBody.rows.length);

  const className = amount > 0 ? "positive" : "negative";
  const descShort = descriprtion.substring(0, 50);

  const showButton  = document.createElement("button");
  showButton.textContent = "Show";
  showButton.value = id;
  showButton.onclick = () => {
    showTransaction(id);
  };
  showButton.className = "show";

  const deleteButton = document.createElement("button");
  deleteButton.textContent = "Delete";
  deleteButton.value = id;
  deleteButton.onclick = () => {
    deleteTransaction(id);
  };
  deleteButton.className = "delete";
  const td = document.createElement("td");

  td.appendChild(deleteButton);
  td.appendChild(showButton);

  newRow.className = className;
  newRow.id = `row_${id}`;
  newRow.innerHTML = `
        <td>${id}</td>
        <td>${date}</td>
        <td>${amount}</td>
        <td>${category}</td>
        <td>${descShort}</td>
  `;

  newRow.appendChild(td);

  calculateTotal();
}

/**
 * The function to calculate total amount of all transactions in trarnsactions array and update the html document to display it.
 */  
function calculateTotal() {
  let sum = 0;
  transactions?.forEach((tr) => (sum += Number(tr.amount)));
  document.getElementById("total").textContent = sum.toString();
}

/**
 * The function to delete transaction from html document from table and from transactions array
 * @param {number} id - Id of transaction to delete
 */  
function deleteTransaction(id) {
  document.getElementById(`row_${id}`).remove();
  const newArr = transactions.filter(tr => tr.id != id);
  transactions = newArr;
  console.log(transactions);
  calculateTotal();
}

/**
 * The function to show transaction details in html document
 * @param {number} id - Id of transaction to show
 */ 
function showTransaction(id) {
  const transaction = transactions.find((tr) => (tr.id == id));

  if (transaction) {
    document.getElementById("desc_id").textContent = "Transaction Id: " + transaction.id;
    document.getElementById("desc_date").textContent = "Transaction Date: " + transaction.date;
    document.getElementById("desc_amount").textContent = "Transaction Amount: " + transaction.amount;
    document.getElementById("desc_category").textContent = "Transaction Category: " + transaction.category;
    document.getElementById("desc_desc").textContent = "Transaction Description: " + transaction.descriprtion;
  }
}
