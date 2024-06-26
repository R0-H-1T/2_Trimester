#install.packages("ggplot2")
#install.packages("dplyr")
#install.packages("writexl")

library(dplyr)
library(writexl)

path <- "./data.csv"

data <- read.csv(path) 
str(data)


# What is your current level of education?
education_frequency <- table(data$What.is.your.current.level.of.education.)
education_table <- as.data.frame(education_frequency)
colnames(education_table) <- c("Education Qualification", "Frequency") #renaming column
print(education_table)
write_xlsx(education_table, "result.xlsx")


# Do you attend webinars and seminars related to your study?
attendance_frequency <- table(data$Do.you.attend.webinars.and.seminars.related.to.your.study.)
attendance_table <- as.data.frame(attendance_frequency) # conversion of table to dataframe
colnames(attendance_table) <- c("Attendance Response", "Frequency")
print(attendance_table)
write_xlsx(attendance_table, "result.xlsx")


#  Have you participated in both seminars and webinars for educational purposes?
participation_frequency <- table(data$Have.you.participated.in.both.seminars.and.webinars.for.educational.purposes.)
participation_table <- as.data.frame(participation_frequency)
colnames(participation_table) <- c("Participation Response", "Frequency")
print(participation_table) # print the table
write_xlsx(participation_table, "result.xlsx")


# Do you use online learning resources, such as webinars, in your education?
online_learning_freq <- table(data$Do.you.use.online.learning.resources..such.as.webinars..in.your.education.)
online_learning_table <- as.data.frame(online_learning_freq)
colnames(online_learning_table) <- c("Usage Response", "Frequency")
print(online_learning_table)
write_xlsx(online_learning_table, "result.xlsx")


# How many hours per week do you spend on online learning activities, including webinars and seminars?
online_learning_hours_frequency <- table(data$Perception.of.Webinars...Seminars..I.believe.seminars.and.webinars.are.effective.for.enhancing.student.engagement.)
online_learning_hours_table <- as.data.frame(online_learning_hours_frequency)
colnames(online_learning_hours_table) <- c("Hours per Week", "Frequency")
print(online_learning_hours_table)
write_xlsx(online_learning_hours_table, "result.xlsx")
