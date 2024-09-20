document.addEventListener("DOMContentLoaded", handleDOMContentLoaded)

function handleDOMContentLoaded() {
    const getShareIconContainer = document.getElementById("shareIconContainer")
    getShareIconContainer.addEventListener("click", () => {
        const getShareBubbleContainer = document.getElementById("shareBubbleContainer")
        
        if(getShareBubbleContainer.classList.contains("disable")){
            getShareBubbleContainer.classList.remove("disable")
        } else {
            getShareBubbleContainer.classList.add("disable")
        }

        const getShareIconContainer = document.getElementById("shareIconContainer")

        if(getShareIconContainer.classList.contains("shareIconContainerDefault")) {
            getShareIconContainer.classList.remove("shareIconContainerDefault")
            getShareIconContainer.classList.add("shareIconContainerClick")
        } else {
            getShareIconContainer.classList.remove("shareIconContainerClick")
            getShareIconContainer.classList.add("shareIconContainerDefault")
        }

        const getShareIcon = document.getElementById("shareIcon")
        if(getShareIcon.classList.contains("shareIconDefault")) {
            getShareIcon.classList.remove("shareIconDefault")
            getShareIcon.classList.add("shareIconClick")
        } else {
            getShareIcon.classList.remove("shareIconClick")
            getShareIcon.classList.add("shareIconDefault")
        }
    })
}