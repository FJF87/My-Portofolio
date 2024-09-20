document.addEventListener("DOMContentLoaded", () => {
    const getAllFaq = document.querySelectorAll("#faq")
    getAllFaq.forEach(getFaq => {
        getFaq.addEventListener("click", () => {
            var getDescription = getFaq.childNodes[3]
            var getDescriptionID = getDescription.id
            var getDivImage = getFaq.childNodes[1].childNodes[3]
            if(getDescriptionID == "hideDescription") {
                getDescription.id = "showDescription"
                getDivImage.src = "assets/images/icon-minus.svg"
            } else if(getDescriptionID == "showDescription") {
                getDescription.id = "hideDescription"
                getDivImage.src = "assets/images/icon-plus.svg"
            }
        })
    });
})