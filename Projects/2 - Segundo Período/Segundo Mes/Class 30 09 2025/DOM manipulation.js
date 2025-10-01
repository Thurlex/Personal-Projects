const addItem = document.getElementById('btnList');
const addChange = document.getElementById('btnChange');
const addMode = document.getElementById('btnMode');
const list = document.getElementById('listThing');
let itemList = 3;
let titleChange = 0;

addItem.addEventListener('click', () => {
    itemList++;
    const newList = document.createElement('li');
    newList.textContent = `${itemList}th item`;
    list.appendChild(newList);
})