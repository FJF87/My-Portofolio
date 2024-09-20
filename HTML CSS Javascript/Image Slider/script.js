let currentImage = 0;

const dateFunction = new Date();
let currSecond = dateFunction.getSeconds();

document.addEventListener("DOMContentLoaded", () => {
    document.querySelector("#prev").onclick = handlePrevClick;
    document.querySelector("#next").onclick = handleNextClick;
    setInterval(handleNextClick, 2000);
})

const imageList = ["cat.jpeg", "dog.jpg", "hamster.jpg", "lovebird.jpg"];

function handlePrevClick(){
    if(currentImage <= 0){
        currentImage = 3;
    }else{
        currentImage--;
    }
    showImage();
}

function handleNextClick(){
    if(currentImage >= 3){
        currentImage = 0
    }else{
        currentImage++;
    }
    showImage();
}

function showImage(){
    let imageSrc = "image/" + imageList[currentImage];
    document.querySelector("#image").src = imageSrc;
}

// use javascript async funtion? to make the image change for every ... seconds
// function handleChangeImagePerSecond(){
//     if(currSecond%3 == 0){
//         currentImage++;
//     }
//     showImage();
// }