/**
 * Fetch random activity from https://www.boredapi.com/api/activity/ and populate html element with id "activity" with data.
 * Uses .then function. 
 * In case of error, displays "К сожалению, произошла ошибка" text.
 * @return {void} 
 */
export function getRandomActivity() {
  console.log("getRandomActivity called");
  fetch("https://www.boredapi.com/api/activity/")
    .then((response) => response.json())
    .then((data) => {
      console.log(JSON.stringify(data));
      document.getElementById("activity").innerHTML = data.activity;
    })
    .catch((err) => {
      document.getElementById("activity").innerHTML =
        "К сожалению, произошла ошибка";
    });
}

/**
 * Fetch random activity from https://www.boredapi.com/api/activity/ and populate html element with id "activity" with data.
 * Uses async/await syntax. 
 * In case of error, displays "К сожалению, произошла ошибка" text.
 * @return {Promise<void>} 
 */
export async function getRandomActivityAsync() {
  console.log("getRandomActivityAsync called");
  try {
    const response = await fetch("https://www.boredapi.com/api/activity/");
    const data = await response.json();
    console.log(JSON.stringify(data));
    document.getElementById("activity").innerHTML = data.activity;
  } catch (err) {
    document.getElementById("activity").innerHTML =
      "К сожалению, произошла ошибка";
  }
}

/**
 * Fetch random activity from https://www.boredapi.com/api/activity/ and populate html element with id "activity" with data.
 * Uses async/await syntax. 
 * @return {Promise<object|string>} data json object obtained from fetch or "К сожалению, произошла ошибка" string in case of error.
 */
export async function getRandomActivityAsyncTwo() {
  console.log("getRandomActivityAsyncTwo called");
  try {
    const response = await fetch("https://www.boredapi.com/api/activity/");
    const data = await response.json();
    return data;
  } catch (err) {
    return "К сожалению, произошла ошибка";
  }
}

/**
 * Populates html element with id "activity" with data.
 * If data has a property "activity", populate element with it, otherwise populate with data (in that case it's a string).
 * @param {object|string} data - Data to display (an object obtained from request or a string in case of error)
 * @return {Promise<void>} 
 */
export async function updateActivity(data) {
  console.log("updateActivity called");
  console.log(JSON.stringify(data));
  document.getElementById("activity").innerHTML = data.activity ?? data;
}
