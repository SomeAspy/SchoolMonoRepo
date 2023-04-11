//create variables
//the vars can be set to whatever. I'm too lazy to make it a function. 
var playerOneValue = "Torch" 
var playerTwoValue = "Gold"
var cache = ""
//return before
console.log("Old set")
console.log("Player One: " + playerOneValue)
console.log("Player Two: " + playerTwoValue) 
console.log(" ") //adds blank line, purely for looks
//swap values
var cache = playerOneValue
var playerOneValue = playerTwoValue
var playerTwoValue = cache
//return new set
console.log("Swapped set")
console.log("Player One: " + playerOneValue)
console.log("Player Two: " + playerTwoValue) 

/*
Basically the way this works is it has 3 variables created at start. the Player 1 value, Player 2, and an empty cache.
those original sets are then logged to console just so you can see it works.
values are swapped by first setting the cache variable to player one's value. player one's value is then replaced with player two's value. then finally, player two's value
is set to the value in cache, which is player one's original value. 
after that is finished the results are logged to console. 
as for using different inputs the vars can be set to anything you like.
this was written in Javascript by Aiden Baker. 
*/