
function verify() { 
  var passwords = ['user1@gsfcu','user2@gsfcu','user3@gsfcu'];
  var usernames = ['person 1','person 2','person 3'];

  var enteredUsername = document.getElementById("username").value;
  var enteredPassword = document.getElementById("password").value;

  var isUsernameCorrect = false;
  var isPasswordCorrect = false;

  for(var i = 0; i < usernames.length; i++) {
      if(enteredUsername === usernames[i]) {
          isUsernameCorrect = true;
          if(enteredPassword === passwords[i]) {
              isPasswordCorrect = true;
              break;
          }
      }
  }

  if(!isUsernameCorrect) {
      alert("You have entered wrong username");
      document.getElementById("username").value = "";
      return; 
  }

  if(!isPasswordCorrect) {
      alert("You have entered wrong password");
      document.getElementById("password").value = "";
      return; 
  }

  window.open("e_comm_website.html", "_self");
}
