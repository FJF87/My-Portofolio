document.addEventListener("DOMContentLoaded", function() {
    document.querySelector("#color-list").onclick = handleChangeColorList;
    document.querySelector("#random-hex").onclick = handleRandomColorHex;
});

let activeColorNumber = 0;
const colorList = ["red", "blue", "yellow", "green", "black", "white"];
const hexChar = ["0", "1", "2", "3", "4", "5"," 6", "7", "8", "9", "A", "B", "C", "D", "E", "F"];

function handleChangeColorList()
{
    // getBtn.addEventListener("click", () => {
    document.querySelector("body").style.backgroundColor = colorList[activeColorNumber];
    document.querySelector("#current-color").innerHTML = colorList[activeColorNumber] ;
    if(activeColorNumber < colorList.length - 1) {
        activeColorNumber++;
    } else {
        activeColorNumber = 0;
    }
    // })
    // document.getElementById(cu)
};

function handleRandomColorHex()
{
    let randomColor = "#";
    let i = 0;
    for (let i = 0; i < 6; i++){
        randomColor += hexChar[Math.floor(Math.random() * 16)];
    }

    document.querySelector("body").style.backgroundColor = randomColor;
    document.querySelector("#current-color").innerHTML = randomColor;
}