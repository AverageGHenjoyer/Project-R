# Project-R (Refresh sklep.pgg.pl)
Program to refresh a website until it loads correctly, and adds wanted items to shoping cart, it is made specifically for sklep.pgg.pl website
(personal use)

# Setup
- If you have two monitors, place your browser on the first one (probably left)
- Make sure you are logged in on a sklep.pgg.pl website
- Enter website so it is visible on a fullscreen (not F11)
- Make sure that web browser window is active (click anywhere on it)
- Scroll website max to the top
- Dont move your mouse while program is working

# Usage
To buy products from this website efficiently you will have to most likely do it in two steps.
1. Use program on a option 2 ("2. Odswierzanie z dodawaniem do koszyka") while refreshing addres "sklep.pgg.pl" just to add items to the cart
If first step was succesful then proced to step 2
2. Use program on a option 1 ("1. Tylko odswierzanie") while refreshing addres "sklep.pgg.pl/koszyk" to try and actually buy the product

# Important
Program automaticly selects to add 2000kg of produt to the cart right now (will be changed to match users preferences)
Program only has 4 options to choose from for now

# WHAT THE CODE DOES:
0. Ask for buying preferences, working mode and count down
1. Get colour of pixel on screen on x,y position
2. Write out RGB values of that pixel(turned off)
3. Presses F5 button until the coulor is desired
4. Press down until option to add product to cart is visible
5. Click that option
6. Turn off

#Might require some .dll files (will check and update so it doesn't)
#32bit build
//TODO add comments, add more user preference options
//WIP gui in Qt
