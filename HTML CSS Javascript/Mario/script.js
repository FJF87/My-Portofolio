document.addEventListener("DOMContentLoaded", function() {
    document.querySelector("#board").onclick = jumpFunction;
})

function start() {
    const getBlock = document.getElementById("block");
    getBlock.style.display = "block";
    getBlock.classList.add("blockAnimation");

    const getBacksound = document.getElementById("backsound");
    getBacksound.currentTime = 0;
    getBacksound.volume = 1.0;
    getBacksound.play();
}

function jumpFunction() {
    const getPlayer = document.getElementById("player");
    const getMarioJumpSound = document.getElementById("marioJumpSound");
    if(getPlayer.classList != "playerJump")
    {
        getMarioJumpSound.currentTime = 0;
        getMarioJumpSound.volume = 0.2;
        getMarioJumpSound.play();
        getPlayer.src = "image/mario-jump.jpeg";
        getPlayer.classList.add("playerJump");
        setTimeout(function(){
            getPlayer.classList.remove("playerJump");
            getPlayer.src = "image/mario-idle.png";
        }, 1000);
    }
}

var gameOver = setInterval(function() {
    const getPlayer = document.getElementById("player");
    const getBlock = document.getElementById("block");
    const playerTop = parseInt(window.getComputedStyle(getPlayer).getPropertyValue("top"))
    const blockLeft = parseInt(window.getComputedStyle(getBlock).getPropertyValue("left"))

    const getMarioDeadSound = document.getElementById("marioDeadSound");
    const getBacksound = document.getElementById("backsound");
    if((blockLeft >= 50 && blockLeft <= 100) && (playerTop >= 300 && playerTop <= 350))
    {
        getBacksound.pause();
        getMarioDeadSound.currentTime = 0;
        getMarioDeadSound.volume = 1.0;
        getMarioDeadSound.play();
        getBlock.classList.remove("blockAnimation");
        getBlock.style.display = "none";
        setTimeout(function() {
            alert("game over");
        }, 1000)
    }
}, 10)