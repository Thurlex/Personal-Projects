const addItem = document.getElementById('btnList');
const addChange = document.getElementById('btnChange');
const addMode = document.getElementById('btnMode');
let itemList = 3;
let titleChange = 0;

addItem.addEventListener('click', () => {
    itemList++;
    const newList = document.createElement('li');
    newList.textContent = `${itemList}th item`;
    document.body.appendChild(newList);
})