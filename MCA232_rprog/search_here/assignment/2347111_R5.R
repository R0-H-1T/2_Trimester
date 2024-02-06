# The easiest way to get ggplot2 is to install the whole tidyverse:
# install.packages("tidyverse")

# load the required libraries
# ggplot is for plotting
# dplyr is for easy data frame manipulation
# readxl for working with Microsoft Excel file
library(ggplot2)
library(dplyr)
library(readxl)

# read the *.xlsx file that has the survey responses
dataset <-
    read_xlsx(path = "/home/bivas/dev/mca/2/asr/assignment/17-Influence of Webinars and Seminars on Students’ Academic Performance.xlsx")

# clean up the dataset by dropping columns
# not needed for demographic analysis
demographic_dataset = select(
    dataset,
    "What is your current level of education?",
    "Do you attend webinars and seminars related to your study?",
    "Have you participated in both seminars and webinars for educational purposes?",
    "Do you use online learning resources, such as webinars, in your education?",
    "How many hours per week do you spend on online learning activities, including webinars and seminars?"
)

demographic_dataset <- na.omit(demographic_dataset)

# plots
education_counts <- table(survey_data$EducationLevel)
pie(education_counts, labels = levels(survey_data$EducationLevel), main = "Education Level Distribution")

pie(
    table(demographic_dataset$`What is your current level of education?`),
    labels = unique(demographic_dataset$`What is your current level of education?`),
    main = "Education Level"
)

Education <-
    demographic_dataset$`What is your current level of education?`
ggplot(demographic_dataset,
       aes(x = Education,
           y = Education,
           fill = Education)) +
    geom_bar(width = .5, stat = "identity") +
    labs(title = "Education Level Distribution", x = "", y = "") +
    coord_polar("y", start = 0)


Attendace <-
    demographic_dataset$`Do you attend webinars and seminars related to your study?`
ggplot(demographic_dataset,
       aes(x = Attendace, y = Attendace, fill = Attendace,)) +
    geom_bar(width = .5, stat = "identity") +
    labs(title = "Education Level Distribution", x = "", y = "") +
    coord_polar("y", start = 0)

Participation <- factor(demographic_dataset$`Have you participated in both seminars and webinars for educational purposes?`)

ggplot(
    data = demographic_dataset,
    aes(
        x = Participation,
        y = Participation,
        fill = Participation
    ) +
        geom_bar(width = .5, position = "fill") +
        labs(title = "Participation in Webinars & Seminars")
)

ggplot(demographic_dataset,
       aes(x = Participation, y = Participation, fill = Participation,)) +
    geom_bar(width = .5, stat = "identity") +
    labs(title = "Participation in Webinars & Seminars", x = "", y = "") +
    coord_polar("y", start = 0)

Usage <- factor(
    demographic_dataset$`Do you use online learning resources, such as webinars, in your education?`
)
ggplot(data = demographic_dataset, aes(x = "", fill = Usage)) +
    geom_bar(width = 1, position = "fill") +
    coord_polar(theta = "y") +
    labs(title = "Use of Online Learning Resources")

















ggplot(data = demographic_dataset, aes(x = HoursSpent, fill = ..count..)) +
    geom_histogram(binwidth = 1, color = "black", position = "identity") +
    labs(title = "Hours Spent on Webinars & Seminars", x = "Hours per Week", y = "Count")


# Convert 'HoursSpent' to numeric if it's not already
demographic_dataset$`How many hours per week do you spend on online learning activities, including webinars and seminars?` <- as.numeric(as.character(demographic_dataset$`How many hours per week do you spend on online learning activities, including webinars and seminars?`))

# Load ggplot2 library
# library(ggplot2)

HoursSpent <- factor(
    demographic_dataset$`How many hours per week do you spend on online learning activities, including webinars and seminars?`
)

# Histogram for Hours Spent on Webinars & Seminars
ggplot(data = demographic_dataset, aes(x = HoursSpent, fill = ..count..)) +
    geom_histogram(color = "white", position = "identity", stat = "count") +
    labs(title = "Hours Spent on Webinars & Seminars", x = "Hours per Week", y = "Count") +
    theme_minimal()
