# List-of-Companies

This is a GUI Qt (C++) application that maintains a list of companies. There are 2 types of companies: 'For Profit' and 'Not for profit'. Each list of the company is maintained separately.

A 'Not for profit' company is also allowed to be ‘charitable’. 
A user is able to input data for the two types of companies. If data for one of the types of company is being added, the user is not able to add data for the other type. 

Both of the lists are displayed on the GUI as the lists are being added. 

When the application is closed, the lists are written to two files (backupFP.txt and backupNFP.txt) with each file containing the list of companies. backupFP.txt contains the list of 'For Profit' companies and backupNFP.txt contains the list of 'Not for profit' companies. 

When the application is started, the application will read from the files and it will display the list of companies on the GUI, i.e. the lists are saved each time the application are closed. 

The data members of the lists are accessed via meta-objects.

