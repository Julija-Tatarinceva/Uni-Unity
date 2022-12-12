/*
 * Work in this file.
 *
 */

// Task 1

function compare(a, b) {
	if (Number(a["id"]) < Number(b["id"])) {
		return -1; // or any negative number
	}
	if (Number(a["id"]) > Number(b["id"])) {
		return 1; // or any positive number
	}
	return 0;
}

let arr = [ {id : "4", name : "Joe"}, {id : "1", name : "Mary"}, {id : "100", name : "Jane"} ];
let result = arr.sort(compare);

console.log("Result of sorting (task #1):");
console.log(result);


// Task 2
// defining the necessary global variables
var words = [];
var word_select = document.getElementById("word-select"); 
var word_output = document.getElementById("word-output"); 
var translate_button = document.getElementById("translate-button"); 
var text_input = document.getElementById("text-input"); 
var text_output = document.getElementById("text-output"); 

/* create a list of dictionary words */
for (let i in my_dict) {
    words.push(i);
}

words.sort(); // sorting the array of words

window.onload = function () {
    /* this code gets executed when the page has loaded */

	// ---------------------------------- populating word select with words from the array ----------------------------------	
	
	for (let i in words) {
		let el = document.createElement("option"); // create a new option element
		el.textContent = words[i]; // set text of the option
		el.value = words[i]; // set the value of the option
		word_select.appendChild(el); // add the newly created option element as a child to the word select
	}
	
	// ---------------------------------- word translation functionality ----------------------------------
	
	function translate(word) { // this function must translate a word in English into Latvian
		return my_dict[word]; //returns the value from my_dict with the name "word"
	}
	
	function showTranslation() { // this function is executed when a user chooses a word from the drop-down list
		
		let word = word_select.selectedOptions[0].value; // get the selected word
		
		let trans = translate(word); // get word translation
		
		word_output.textContent = trans; // show translated word
		
	}
	
	word_select.addEventListener('change', showTranslation); // the function showTranslation will be automatically executed when a user changes selected word in the drop-down list
	
	// ---------------------------------- text translation functionality ----------------------------------
	
	function translateText(text) { // this function must translate a text in English into Latvian 
		// split the text into words, translate each word ignoring case, leave words without translations available in my_dict.
		let words = text.split(" "); //splits string using the character in brackets
		for (let i in words){
			if(words[i].toLowerCase() in my_dict) words[i] = my_dict[words[i].toLowerCase()];
		}
		return words.join(' '); //adds all the elements of an array separated by the specified separator
	}
	
	function showTextTranslation() { // this function is executed when a user presses a button Translate
		
		let text = text_input.value; // get the text to translate
		
		let trans = translateText(text); // get text translation
		
		text_output.textContent = trans; // show translated text
		
	}
	
	translate_button.addEventListener('click', showTextTranslation); // the function showTextTranslation will be automatically executed when a user clicks the Translate button
		
}
