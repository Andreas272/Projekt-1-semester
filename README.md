# P1---train-vs-planes


Before running the code change the working directory to "src", else can't the scan_data.c not see the file "data.txt"

User manuel: 

Step 1. Choose a data file to be used, if my_data.txt is chosen a unit have to be picked.

Step 2. Input the wanted starting location.

Step 3. Input the wanted end location.

Step 4. Watch the magic happen ;)

Step 4. Make the Choice, 
0 = Exit program, 
1 = Rerun fastest route cal, 
2 = Change route, 
3 = print array. 




Information on datafiles:

my_data allows the user to input their own data in the text file. 

When creating additional datafiles it is important that the format of the files are kept the same as the existing ones. Therefore the data should be appended to the files with the following format: 
Depaturestation, arrivalstation, duration of travel.

When the option of inputting own data in my_data.txt is used, then the user should be aware that they need to specify if the data is in minutes or hours when asked.

It is also important to notice that the file plane_txt should be used when inputting own flight data. The format of the data should also be in the above mentioned format.


data_4Stations_hours.txt is based on imaginary data. <br />
data_6Stations_hours.txt is based on imaginary data. <br />
data_11Stations_hours.txt is based on imaginary data. <br />
data_11Stations_minutes.txt is based on train times from Google Maps and flight times from Momondo.<br />

Data used in data_11Stations_minutes.txt are based on following cities,
the star represents that the city have an allocated airport:
1. Frankfurt*
2. Darmstadt
3. Mannheim
4. Heidelberg
5. Wurzberg
6. Stuttgart*
7. Nurnberg
8. Ulm
9. Augsburg
10. Regensburg
11. München*
