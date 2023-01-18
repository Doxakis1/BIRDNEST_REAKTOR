written before I started working on the project
________________________________________________________________________________________________
This is my plan for the exercise at hand.

I decided that I will be solving this problem in C.

Why C:
	Although I undestand and know that C is not a very popular option for when it comes to website backend development, I decided to use it nevertheless since it is the language I am most familiar with. Furthermore the application requires that data is constantly updated and for that reason C would be great as the code will be excecuted very quickly.

The implementation:
	My vision is to have a C program run every 1,8 seconds that takes in the information from the website provided by Reaktor (http://assignments.reaktor.com/birdnest/drones) that holds the data, proccesses it and find any drone violations. When it finds a violation, it requests the users details from the database provided by the Reaktor (http://assignments.reaktor.com/birdnest/pilots/:serialNumber) and then audits it. Lastly I am planning to use Javascript alongsides CSS and HTML to present the collected data in real time to the requester.

Limitations: This is the first such challenge I ever tackle. I am very excited to take this challenge on and explore all the interesting impelementations of C for webdevelopment.
>>>>>


_____________________________________________________________________________________________________________________________________________


Written after I finished the project


These are my final notes before submitting the project.

Was C a good idea? 
	Although speed-wise C does a charming work for this task. The ammount of debugging I had to do was not worth the speed. It was fun as a challenge but in the future I will prompt to use other languages to compelete such backend.
	
How is the hosting done?
	I am running the script on a Google drive server running with apache. 
The project does not have a makefile as the libraries used require different commands on different OS:s.
