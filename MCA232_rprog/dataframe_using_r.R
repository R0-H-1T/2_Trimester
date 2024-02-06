# Dataframe
# consists of rows and cols
# no.of cols should be the same
name = c("Michael", "Rick", "Alex", "Donald")
age = c(12,34,24,45)
height = c(5.6,5.8,5.3,5.7)
weight = c(56, 59, 62, 74)
gender = factor(c("M", "M", "F", "M"))

data = data.frame(name, age, height, weight, gender)
data
dim(data) #rows and cols

data[1,3] # 1 row , 3 col - elem will be picked
data[c(1, 3), 4] # 1st row and 3 row, and 4 col -> elem will be picked
data
# ways of accessing the cols values -----------------------
data$age #Prints entire cols value
data["age"] 
data[2] 

#------------ SUMMARY ------------------------
summary(data) # prints min, median , max


# ----------------- INTERMEDIATE -------------------------------

StudPlacemenetDataA = data.frame(
  stud_id = c(2347101:2347103),
  stud_name = c("Sonny", "Erik", "Emmanuel"),
  gender = factor(c('Female', 'Female', 'Male')),
  salaryk = c(8, 2, 9),
  joining_data = as.Date(c("2023-11-08", "2023-1-09", "2023-12-12")),
  stringsAsFactors = FALSE
)
StudPlacemenetDataA
?data.frame
StudPlacemenetDataB = data.frame(
  stud_id = c(2347201:2347203),
  stud_name = c("Michael", "John", "Samuel"),
  gender = factor(c("Male", "Female", "Male")),
  salaryk = c(5, 6, 2),
  joining_data = as.Date(c("2023-12-12", "2023-9-24", "2023-05-01")),
  stringsAsFactors = FALSE
)

StudPlacemenetDataB

# gender: Factor w/ 2 levels "F","M": 2 2 1 2 
str(data)

#if forgot to add a field, you can do this lik -->
StudPlacemenetDataB$Joblocation = c("Kolkata", "Delhi", "Pune")
StudPlacemenetDataB
StudPlacemenetDataA$Joblocation = c("Punjab", "Jharkand", "Chennai")
StudPlacemenetDataA

#another way of doing this by using c bind - column bind
ageA = c(23,25,32)
ageB = c(25,22,29)
StudPlacemenetDataB = cbind(StudPlacemenetDataB, age)
StudPlacemenetDataB
StudPlacemenetDataA = cbind(StudPlacemenetDataA, age)
StudPlacemenetDataA

#for merging two columsn
TotalStudents = rbind(StudPlacemenetDataA, StudPlacemenetDataB)
TotalStudents

is.ordered(data$gender) # is it ordinal, It is norminal
v = c(12,34 ,23, 43)
v3 = as.ordered(v)
v3
# is, as,

TotalStudents
## FILTERING DATA -> where clause
#nrow for getting count of rows.
nrow(subset(TotalStudents, salaryk >= 5))
TotalStudents[,-5] # except columns Joblocation

# change the row name 
# rows are referred as observation in R language
rownames(TotalStudents) = c("row1", "row2", "row3", "row4" "row5", "row6")
colnames(TotalStudents) = c("id", "name", "salary_in_k", "joining_date", "location", "age")


# To have a more verbose comment use comment, attribute
#applicable for all datatypes
comment(TotalStudents) = "MCA-Students placement details"
attributes(TotalStudents) # check all attributes of dataframe
summary(TotalStudents)

#accessing -> 1
TotalStudents[2:3,] #
#accessing -> 1
TotalStudents[c("row1", "row3"),]
TotalStudents[1:2, c(1,3)]
#create a vector, access using vector c(1,2,3)


#dataset and dataframe diff
#collecting info and storing in  table
#default datasets present in r
carsData = mtcars
summary(carsData)
str(carsData)




carsData$gear = factor(carsData$gear)
carsData$am = factor(carsData$am)

str(carsData)
carsData
carsData[2]

carsData
carsData[which.max(carsData$disp),]
nrow(subset(carsData, am == 0))
rownames(carsData[which.max(carsData$wt),])
nrow(subset(carsData, am == 0 & cyl == 4))
?which
#
#Ques - average weight of 8 syl v
# Heaviest vehicle - automatic or manual
?mean
?median
?range
#as.factor - nominal, different types none are better thatn the other, just
#       different type.
#as.ordered() - ordinal, like ranking in competitive eam


## -------------------------- MEAN MEDIAN MODE ---------------------------------------

str(carsData)
cyls <- select(mtcars, cyl)
meancyl = mean(carsData[2], na.rm = TRUE)
meancyl
carsData[1,1]

# cex - font size
# las - orientation of the x axis
# x axis label
# pch - pointer character - any symbol to represent for testing :
plot(x, pch=1)
plot(x, pch=14)

#par  partition
#2 rows 2 cols - 4 graphs can be made
#mfrow()
# col - color, for data point
plot(lynx, main="Testing", col.main = 45, cex.main=3.5, las=0,
    xlab="xlabel", ylab="ylabel", pch=12, col="red")


lynx
