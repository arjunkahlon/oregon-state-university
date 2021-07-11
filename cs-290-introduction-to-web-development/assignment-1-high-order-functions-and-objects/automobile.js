//Arjun Kahlon
//CS 290 - HW Assignment: Higher-Order Functions and Objects

function Automobile( year, make, model, type ){
    this.year = year; //integer (ex. 2001, 1995)
    this.make = make; //string (ex. Honda, Ford)
    this.model = model; //string (ex. Accord, Focus)
    this.type = type; //string (ex. Pickup, SUV)
}

var automobiles = [ 
    new Automobile(1995, "Honda", "Accord", "Sedan"),
    new Automobile(1990, "Ford", "F-150", "Pickup"),
    new Automobile(2000, "GMC", "Tahoe", "SUV"),
    new Automobile(2010, "Toyota", "Tacoma", "Pickup"),
    new Automobile(2005, "Lotus", "Elise", "Roadster"),
    new Automobile(2008, "Subaru", "Outback", "Wagon")
    ];

/*This function sorts arrays using an arbitrary comparator (don't use builtin sort). You pass it a comparator and an array of objects appropriate for that comparator and it will return a new array which is sorted with the largest object in index 0 and the smallest in the last index*/
function sortArr( comparator, array ){
    /*your code here*/
    //make a copy of passed in array as a new array object
    var arrCpy = array.slice(0);    
    //declare variable that will be used to swap
    var swapVal;  

    //Bubble sort algorithm for sorting cars 
    for(var a = 0; a < arrCpy.length - 1; a++)  
    {
        for(var b = a + 1; b < arrCpy.length; b++) 
        {
            if(comparator(arrCpy[b], arrCpy[a]))    
            {
                //store current index in variable for swap
                swapVal = arrCpy[a];
                //update current a index to b
                arrCpy[a] = arrCpy[b];
                //update j to swap variable
                arrCpy[b] = swapVal;
            }
        }
    }
    //return sorted array object
    return arrCpy;
}

/*A comparator takes two arguments and uses some algorithm to compare them. If the first argument is larger or greater than the 2nd it returns true, otherwise it returns false. Here is an example that works on integers*/
function exComparator( int1, int2){
    if (int1 > int2){
        return true;
    } else {
        return false;
    }
}

/*For all comparators if cars are 'tied' according to the comparison rules then the order of those 'tied' cars is not specified and either can come first*/

/*This compares two automobiles based on their year. Newer cars are "greater" than older cars.*/
function yearComparator( auto1, auto2){
    /* your code here*/
    return ((auto2.year - auto1.year) < 0);
}

/*This compares two automobiles based on their make. It should be case insensitive and makes which are alphabetically earlier in the alphabet are "greater" than ones that come later.*/
function makeComparator( auto1, auto2){
    /* your code here*/
    if(auto1.make.toLowerCase() > auto2.make.toLowerCase()) {
        return true;
    }
    else {
        return false;
    }
}

/*This compares two automobiles based on their type. The ordering from "greatest" to "least" is as follows: roadster, pickup, suv, wagon, (types not otherwise listed). It should be case insensitive. If two cars are of equal type then the newest one by model year should be considered "greater".*/
function typeComparator( auto1, auto2){
    /* your code here*/
    //list the order on which we will rank the automobiles
    var typeOrder = ['wagon', 'suv', 'pickup', 'roadster'];

    //assign comparison variables by utilizing rank index
    var compare1 = typeOrder.indexOf(auto1.type.toLowerCase());
    var compare2 = typeOrder.indexOf(auto2.type.toLowerCase());

    //account for when the comparator compares the same type
    if (compare1 === compare2) {
        //return based on year if same type
        return auto1.year > auto2.year;
    } 
    else {
        return compare1 > compare2;
    }
}

Automobile.prototype.logMe = function(a) {
    if(a == true) {
        console.log(this.year, this.make, this.model, this.type)
    } 
    else {
        console.log(this.year, this.make, this.model)
    }
}
//print function that outputs via call to above logMe function
function printCars(cars, bool)
{
    cars.forEach(function(a)
    {
        a.logMe(bool);
    })
}


/*Your program should output the following to the console.log, including the opening and closing 5 stars. All values in parenthesis should be replaced with appropriate values. Each line is a seperate call to console.log.

Each line representing a car should be produced via a logMe function. This function should be added to the Automobile class and accept a single boolean argument. If the argument is 'true' then it prints "year make model type" with the year, make, model and type being the values appropriate for the automobile. If the argument is 'false' then the type is ommited and just the "year make model" is logged.

*****
The cars sorted by year are:
(year make model of the 'greatest' car)
(...)
(year make model of the 'least' car)

The cars sorted by make are:
(year make model of the 'greatest' car)
(...)
(year make model of the 'least' car)

The cars sorted by type are:
(year make model type of the 'greatest' car)
(...)
(year make model type of the 'least' car)
*****

As an example of the content in the parenthesis:
1990 Ford F-150 */


//call sortArr to sort cars by year from greatest to lowest
var sortYear = sortArr(yearComparator, automobiles);  

//call sortArr to sort cars by make from greatest to lowest
var sortMake = sortArr(makeComparator, automobiles); 

//call sortArr to sort cars by type from greatest to lowest 
var sortType = sortArr(typeComparator, automobiles);   

//Beginning of output
console.log("*****");

//console output that conforms to assignment prompt for year
console.log("The cars sorted by year are:");
console.log("year make model of the 'greatest' car");

//Prints cars sorted by year from greatest to lowest
printCars(sortYear, false);
console.log("year make model of the 'least' car");
//End of: console output that conforms to assignment prompt for year

//console output that conforms to assignment prompt for make
console.log("The cars sorted by make are:");
console.log("year make model of the 'greatest' car");

//Prints cars sorted by make from greatest to lowest
printCars(sortMake, false);
console.log("year make model of the 'least' car");
//End of: console output that conforms to assignment prompt for make

//console output that conforms to assignment prompt for type
console.log("The cars sorted by type are:");
console.log("year make model type of the 'greatest' car");

//Prints cars sorted by type from greatest to lowest
printCars(sortType, false);
console.log("year make model type of the 'least' car");
//End of: console output that conforms to assignment prompt for type

console.log("*****");
//End out output

