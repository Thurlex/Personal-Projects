    const deleteParagraph = document.getElementById('deleteThisParagraph');
    const deleteButton = document.getElementById('paragraphDeleter');
    const addParagraph = document.getElementById('paragraphCreator');
    let paragraphCounter = 0;

    deleteButton.addEventListener('click', () => {
        const paragraphsToDelete = document.querySelectorAll('.deleteThisParagraph');
        if (paragraphsToDelete.length > 0) {
            paragraphCounter--;
            paragraphsToDelete[paragraphsToDelete.length - 1].remove(); // Removes the last paragraph
            paragraph.remove();
        }
    });

    addParagraph.addEventListener('click', () => {
        paragraphCounter++;
        const newParagraph = document.createElement('p');
        newParagraph.textContent = `I am child number ${paragraphCounter}`;
        newParagraph.classList.add('deleteThisParagraph');
        document.body.appendChild(newParagraph);
    })
