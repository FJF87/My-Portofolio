document.addEventListener("DOMContentLoaded", () => {
    var inputRating = 0;

    var getAllNumberButton = document.getElementById("numberButton").querySelectorAll("button")
    console.log(getAllNumberButton)
    getAllNumberButton.forEach(getNumberButton => {
        getNumberButton.addEventListener("click", () => {
            if(getNumberButton.classList.contains("circleButtonSelected")) {
                getNumberButton.classList.remove("circleButtonSelected")
                inputRating = 0
            } else if(!getNumberButton.classList.contains("circleButtonSelected")) {
                getNumberButton.classList.add("circleButtonSelected")
                if(inputRating != 0) {
                    console.log(`input rating not 0, but ${inputRating}`)
                    const idToBeRemoved = `number${inputRating}`
                    console.log(idToBeRemoved)
                    const getButtonToBeRemoved = document.querySelector(`#${idToBeRemoved}`)
                    console.log(getButtonToBeRemoved)
                    getButtonToBeRemoved.classList.remove("circleButtonSelected")
                }
                inputRating = getNumberButton.innerText
            }
        })
    });

    const getSubmitButton = document.getElementById("confirmButton")
    getSubmitButton.addEventListener("click", () => {
        if(inputRating != 0) {
            const mainArticle = document.querySelectorAll("article")
            mainArticle[0].classList.remove("enable")
            mainArticle[0].classList.add("disable")
            mainArticle[1].classList.remove("disable")
            mainArticle[1].classList.add("enable")
            document.getElementById("numberSelected").innerHTML = inputRating
        }
    })
})