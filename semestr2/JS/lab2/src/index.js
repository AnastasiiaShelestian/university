import {
  getRandomActivity,
  getRandomActivityAsync,
  getRandomActivityAsyncTwo,
  updateActivity,
} from "./activity.js";

const option = 3;

fetchData();

/**
 * Call the specified function to get activity data each 15 seconds recursively.
 * @return {Promise<void>} 
 */
async function fetchData() {
  switch (option) {
    case 1:
      getRandomActivity();
      break;
    case 2:
      getRandomActivityAsync();
      break;
    case 3: {
      const data = await getRandomActivityAsyncTwo();
      updateActivity(data);
      break;
    }
    default:
      getRandomActivity();
      break;
  }

  setTimeout(fetchData, 15000);
}
