//Referenced W3Schools Web Tutorials for help with this animation

function carousel() 
{
  //to iterate loop
  var i;
 
  //index.html  home page
  var slides = document.getElementsByClassName("slide-show");
 
 //dots displayed below each slide in carousel animation
  var dots = document.getElementsByClassName("dot");
  
  //loop
  for (i = 0; i < slides.length; i++) 
  {
    slides[i].style.display = "none";  
  }
  
  //update slide index
  slideIndex++;
  
  if (slideIndex > slides.length) 
  {
     slideIndex = 1;
  }    
  
  for (i = 0; i < dots.length; i++) 
  {
    dots[i].className = dots[i].className.replace(" active", "");
  }

  slides[slideIndex-1].style.display = "block";  
  
  dots[slideIndex-1].className += " active";
  
  //sets a timer for each slide
  setTimeout(carousel, 5000); // 5 second timer
}

//initialize to 0
var slideIndex = 0;

//run function carousel
carousel();
