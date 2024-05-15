# Лабораторная работа 2 - Promise и async/await

## Запуск проекта

Для запуска проекта локально установите Node.js и пакет static-server.

- Пожалуйста, обратитесь к официальному руководству по установке Node.js [official guide](https://nodejs.org/en/download)
- Чтобы установить static-server, выполните следующую команду или откройте [official documentation](https://www.npmjs.com/package/static-server#getting-started)

```
    npm -g install static-server
```

- Запустите следующую команду в командной строке из директории проекта::

```
    static-server
```

## Функции getActivity

В файле activity.js представлены 3 варианта функций getActivity.
Первая функция (getActivity) использует промисы и метод .then для получения и вставки данных.
Вторая функция (getActivityAsync) использует синтаксис async/await для получения и вставки данных.
Третья функция (getActivityAsyncTwo) также использует синтаксис асинхронных функций, но возвращает только данные. Чтобы заполнить HTML-элемент данными, возвращаемыми getActivityAsyncTwo, используется функция updateActivity.

В настоящее время используемый вариант может быть изменен путем модификации файла index.js, указывая желаемый номер опции.


```javascript
const option = 1;
```
## Краткая документация к проекту
Асинхронные функции играют важную роль в данном проекте, так как они выполняют основную работу, благодаря которой на странице `index.html` появляется случайный текст с действием.

```javascript
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
```
```javascript
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
```

```javascript
export async function getRandomActivityAsyncTwo() {
  console.log("getRandomActivityAsyncTwo called");
  try {
    const response = await fetch("https://www.boredapi.com/api/activity/");
    const data = await response.json();
    return data;
  } catch (err) {
    return "К сожалению, произошла ошибка";
  } }
```
```javascript
export async function updateActivity(data) {
  console.log("updateActivity called");
  console.log(JSON.stringify(data));
  document.getElementById("activity").innerHTML = data.activity ?? data;
}
```


## Контрольные вопросы
** Какое значение возвращает метод fetch?<br>
Метод fetch возвращает объект Promise, который представляет собой асинхронную операцию получения данных из сети. Promise – это специальный объект в JavaScript, представляющий результат операции, которая может быть выполнена сразу, позже или отклонена.

** Что представляет собой Promise?<br>
Promise – это специальный объект в JavaScript, используемый для асинхронных операций. Он может находиться в трех состояниях:

- Ожидание (Pending): Исходное состояние обещания, когда операция еще не завершена.
- Выполнено (Fulfilled): Состояние, когда операция завершена успешно.
- Отклонено (Rejected): Состояние, когда операция завершена с ошибкой.<br>
Promise позволяет структурировать асинхронный код и обрабатывать результат выполнения операции после её завершения, независимо от результата.

** Какие методы доступны у объекта Promise?<br>
У объекта `Promise` есть три метода: then, catch и finally.

- `then` используется для определения действий после успешного выполнения операции.
catch определяет действия при возникновении ошибки.
- `catch` говорит, что делать, если операция закончится неудачей.
- `finally` выполняет код независимо от результата операции.<br>
Эти методы управляют поведением программы в зависимости от результата асинхронных операций, таких как запросы к серверу или загрузка файлов.

**Каковы основные различия между использованием async / await и Promise?<br>
Основные различия между использованием `async/await` и объектов `Promise` связаны с синтаксисом, управлением ошибками и последовательностью операций.

- Синтаксис: `Promise` требует цепочки методов `then()` и `catch()`, что может усложнить чтение кода. В то время как `async/await` позволяет писать асинхронный код, выглядящий как синхронный, что делает его легче для понимания.
- Управление ошибками: В `Promise` ошибки обрабатываются методом `catch()`, что может быть неудобно. С `async/await` ошибки могут быть обработаны с использованием конструкции `try...catch`, что делает код более понятным.
- Последовательность операций: Для последовательного выполнения нескольких операций в Promise требуется цепочка вызовов методов `then()`, что может усложнить код. В `async/await` последовательные операции управляются ключевым словом `await`, что делает код более читаемым и легким в написании.<br>
Таким образом, async/await предоставляет более удобный и интуитивно понятный способ написания асинхронного кода по сравнению с использованием объектов `Promise`.