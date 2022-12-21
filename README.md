# P1---train-vs-planes


Before running the code change the working directory to "src", else can't the scan_data.c not see the file "data.txt"

User manuel: 

Step 1. Input the wanted starting location.

Step 2. Input the wanted end location.

Step 3. Watch the magic happen ;)

Step 4. Make the Choice, 
0 = Exit program, 
1 = Rerun fastest route cal, 
2 = Change route, 
3 = print array. 

Information on datafiles:

my_data allows the user to input their own data in the text file. 

When creating additional datafiles it is important that the format of the files are kept the same as the existing ones. Therefore the data should be appended to the files with the following format: 
Depaturestation,arrivalstation.duration of travel.

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