document.addEventListener("DOMContentLoaded", function() {
	document.querySelector("#addButton").onclick = add;
	document.querySelector("#minusButton").onclick = minus;
})

let counter = 0;

function add()
{
	counter++;
	document.querySelector("h1").innerHTML = counter;
}

function minus()
{
	counter--;
	document.querySelector("h1").innerHTML = counter;
}