    let adverb = ['quickly', 'excitedly', 'angrily', 'happily', 'sadly'];
    let article = ['a', 'the'];
    let preposition = ['under', 'over', 'around', 'near', 'beside', ' '];
    let plural = ['', 's']

    let RArray = function(list) {
        return list[Math.floor(Math.random()*list.length)]; //makes a function named RArray, which chooses a random value from the array provided
    };