//Arjun Kahlon
//CS 290 
//DOM and Events

//In this assignment, we are creating a 4x4 table. The top row will be the table header. The 3 x 3 cell grid 
//will each hold coordinates. By default the top left most cell will be outlined. The user will be presented
//with 5 choices: move up, move down, move left, move right, and mark current cell. The user will not be able
//to wrap around the table when they reach the edges. When a table cell is marked, it will recieve a background
//color of yellow

var vTable = function() 
{
  //initialize variable column to 1
  var column = 1;

  //initialize variable row to 1
  var row = 1;

  function buildTable(btn) 
  {
    //Here, we will build a 4x4 table in which the top row is the header and each cell ir represented by position

     //body node
     var body = document.body;

     //use createElement to create a table
     var table = document.createElement('table');
     table.className="testTable";

     //use createElement for body elements
     var tBody = document.createElement('tbody');
     
     //set width 60%. I prefer the table being smaller sized
     table.style.width = '60%';

     //set default border attribute
     table.setAttribute('border', '1');

     //create cells in table
     for (var a = 0; a <= 3; a++) 
     {
        //add row (4 total)
        var tr = document.createElement('tr');
        for (var b = 0; b <= 3; b++) 
        {
           //break out of loop if we reach end of table
           if (a === 4 && b === 4) 
           {
             //exit loop when end of table
              break;
           } 
           else 
           {
              if (a === 0) //header row
              {
                //Use createElement to create  header
                 var th = document.createElement('th');

                 //Add text to header
                 th.appendChild(document.createTextNode("Header " + (b + 1)));

                 //Append header
                 tr.appendChild(th);
              } 
              else 
              {
                 //Use createElement for table data
                 var td = document.createElement('td');

                 //create positions for each cell in table
                 var label = (b + 1) + "," + a;

                 //Append labels to table
                 td.appendChild(document.createTextNode(label));

                 //set id to label
                 td.setAttribute('id', label);

                 //make starting cell 4px
                 if (b === 0 && a === 1) 
                 {
                    td.style.border = "4px solid black";
                 }
                 tr.appendChild(td);
              }
           }
        }
        //Append tr to table body
        tBody.appendChild(tr);
     }
     //Append table body to table
     table.appendChild(tBody);

     //Append table
     body.appendChild(table);
     
     if (btn) 
     {
        btn();
     }
  }

  function addB(btn) 
  {
    //Buttons will be placed beneath table. There will be 5 total buttons for directions and marking the cell
     var body = document.body;

     //Create array of button selections for each direction and cell marking
     var selections = ["Left", "Up", "Right", "Down", "Mark Cell"];

     for (var a = 0; a < selections.length; a++) 
     {
        //create button that will be appended
        var button = document.createElement('button');

        //Append label to button 
        button.appendChild(document.createTextNode(selections[a]));

        //Apend button to body
        body.appendChild(button);

        //add fucntionality to the buttons
        button.addEventListener("click", function(e) 
        {
            //move the box if user clicks a directional button
            if (e.target.innerText !== "Mark Cell") 
            {
              //move depending on user selected direction
               directionalMove(e.target.innerText);
            } 
            //if user chooses mark cell button, then mark cell in yellow
            else if (e.target.innerText === "Mark Cell") 
            {
              //mark current cell with yellow background
               markCell();
            }
        });
     }
  }

    function directionalMove(buttonSelect) 
  {
     //set cell ID
     var cellID = row + "," + column;

     //get current cell by coordinates
     var currentCell = document.getElementById(cellID);

     //current cell will be reset to default border
     currentCell.style.border = "1px solid black";

    //switch case that will determine direction for movement
     switch (buttonSelect) 
     {
       case "Up":
          //if column is 1, we want to remain on current cell
          if (column > 1) 
          {
            //if colum greater than 1, decrement column when moving up
             column--;
          }
          break;
       case "Down":
         //if column is at 3, we want to remain on current cell
          if (column < 3) 
          {
             //if column less than 3, increment column when moving down
             column++;
          }
          break;
       case "Left":
          //if row is at 1, we want to remain on current cell
          if (row > 1) 
          {
            //if row greater than 1, decrement row when moving left
             row--;
          }
          break;
       case "Right":
          //if row is at 4, we want to remain on current cell
          if (row < 4) 
          {
            //if row lessan than 4, increment row when moving right
             row++;
          }
          break;
     }
     //reset cell ID
     cellID = row + "," + column;

     //reset current cell with coordinates
     currentCell = document.getElementById(cellID);

     //give current cell a solid black outline
     currentCell.style.border = "4px solid black";
  }

  function markCell() 
  {
    //set cell by calling getElementbyId()
     var cell = document.getElementById(row + "," + column);

     //set background color to Yellow when cell is marked
     cell.style["background-color"] = "Yellow";
  }


  //Build the Table
  buildTable(addB);
};

//View the Table
vTable();