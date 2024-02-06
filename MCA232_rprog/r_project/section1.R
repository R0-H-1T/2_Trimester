
# Influence of Webinars and Seminars on Students’ Academic Performance
# ~ Rohit Tank
# 2347161

library(GGally)
library(dplyr)
library(tidyverse)
library(ggplot2)
library(vcd)
library(reshape2)
library(fmsb)
library(gridExtra)


path <- "./data.csv"
data <- read.csv(path) 
str(data)


seminars_effective  = factor(data$Perception.of.Webinars...Seminars..I.believe.seminars.and.webinars.are.effective.for.enhancing.student.engagement., levels = c("Strongly disagree", "Disagree", "Neutral", "Agree", "Strongly agree"), ordered = TRUE)
convenience_webinars = factor(data$Perception.of.Webinars...Seminars..The.convenience.of.webinars.influences.students..participation.., levels = c("Strongly disagree", "Disagree", "Neutral", "Agree", "Strongly agree"), ordered = TRUE)
accomodating_students = factor(data$Perception.of.Webinars...Seminars..Webinars.are.better.at.accommodating.students..busy.schedules.compared.to.seminars.., levels = c("Strongly disagree", "Disagree", "Neutral", "Agree", "Strongly agree"), ordered = TRUE)
peer_interaction = factor(data$Perception.of.Webinars...Seminars..Peer.interaction.is.essential.for.student.learning.in.webinars.., levels = c("Strongly disagree", "Disagree", "Neutral", "Agree", "Strongly agree"), ordered = TRUE)
encourage_participation = factor(data$Perception.of.Webinars...Seminars..Seminars.encourage.active.participation.among.students.., levels = c("Strongly disagree", "Disagree", "Neutral", "Agree", "Strongly agree"), ordered = TRUE)
perceptions = data.frame(seminars_effective, convenience_webinars, accomodating_students, peer_interaction, encourage_participation)
perceptions = na.omit(perceptions)


# Perceptions :
# 1. I believe seminars and webinars are effective for enhancing student engagement
believe_frequency <- data$Perception.of.Webinars...Seminars..I.believe.seminars.and.webinars.are.effective.for.enhancing.student.engagement.
belief_df <- data.frame(Response = believe_frequency)
belief_df$Response <- factor(belief_df$Response, levels = c("Strongly disagree", "Disagree", "Neutral", "Agree", "Strongly agree"))
ggplot(belief_df, aes(x = Response, fill = Response)) +
  geom_bar(stat = "count") +
  labs(title = "Belief in the Effectiveness of Seminars and Webinars", x = "Response", y = "Count") +
  theme_minimal()
#The graph is showing the distribution of people's beliefs about the effectiveness of seminars and webinars for enhancing student engagement.
#By looking at the heights of the bars for each belief level, you can get an idea of how many people in the dataset hold a particular belief. 
#For example, if the bar is tall for "Agree," it means that a significant number of people believe that seminars and webinars are effective for
#enhancing student engagement.




# 2. The convenience of webinars influences students' participation.
ggplot(data, aes(x = as.factor(data$What.is.your.current.level.of.education.), y = as.factor(data$Perception.of.Webinars...Seminars..The.convenience.of.webinars.influences.students..participation..))) +
  #geom_count(aes(color = data$Perception.of.Webinars...Seminars..The.convenience.of.webinars.influences.students..participation.., size = 3)) +
  geom_jitter(position = position_jitter(width = 0.2, height = 0), size = 3) +
  labs(title = "Webinar Convenience and Student Participation",
       x = "Education Level",
       y = "Perception") +
  scale_color_manual(values = c("Strongly disagree" = "red",
                                "Disagree" = "orange",
                                "Neutral" = "yellow",
                                "Agree" = "green",
                                "Strongly agree" = "blue"))
#The scatter plot shows how individuals' education levels correlate with their perceptions of how the convenience of webinars 
#influences student participation. It represent varying levels of agreement or disagreement, offering a visual overview of potential 
#patterns or trends in these associations.



#3 .Webinars are better at accommodating students' busy schedules compared to seminars.
temp_data <- data.frame(
  Education_Level = data$What.is.your.current.level.of.education.,
  Webinar_Response = data$Perception.of.Webinars...Seminars..Webinars.are.better.at.accommodating.students..busy.schedules.compared.to.seminars..
)

mosaicplot(table(data$What.is.your.current.level.of.education., data$Perception.of.Webinars...Seminars..Webinars.are.better.at.accommodating.students..busy.schedules.compared.to.seminars..),
           main = "Perceptions of Webinars Accommodating Busy Schedules",
           color = c("red", "green", "blue", "yellow", "purple"),  
           cex.axis = 0.7,
           las = 4)
#The grouped bar chart visualizes the distribution of responses to the statement "Seminars encourage active participation among students"
#across different levels of education.The chart provides a quick comparison of how the perception of seminar
#effectiveness varies among different educational backgrounds.



# 4. Peer interaction is essential for student learning in webinars.
heatmap_data <- table(data$What.is.your.current.level.of.education., data$Perception.of.Webinars...Seminars..Peer.interaction.is.essential.for.student.learning.in.webinars..)
heatmap_df <- as.data.frame(heatmap_data)
ggplot(heatmap_df, aes(x = Var2, y = Var1, fill = Freq)) +
  geom_tile() +
  labs(title = "Peer Interaction Vital for Webinar Learning",
       x = "Perception",
       y = "Education Level",
       fill = "Count") +
  scale_fill_gradient(low = "white", high = "red")  
#The heatmap visually represents the frequency of responses to the statement 
#"Peer interaction is essential for student learning in webinars" across different education levels.
#The chart provides an overview of how the perception of the importance of peer interaction varies among different educational backgrounds. 
#Each cell in the heatmap corresponds to a combination of education level and perception, 
#with color intensity indicating the count of responses. 





# 5. Seminars encourage active participation among students.

education_levels <- c("High School", "Undergraduate (Bachelor's degree)", "Graduate (Master's or higher)", "Others (please specify)")

# Create a factor with specified levels
data$What.is.your.current.level.of.education. <- factor(data$What.is.your.current.level.of.education., levels = education_levels)

# Create a grouped bar chart
ggplot(data, aes(x = `What.is.your.current.level.of.education.`, 
                 fill = data$Perception.of.Webinars...Seminars..Seminars.encourage.active.participation.among.students..)) +
  geom_bar(position = "dodge", color = "black", stat = "count") +
  labs(title = "Active Engagement: Seminars Inspiring Student Participation",
       x = "Education Level",
       y = "Count",
       fill = "Response") +
  theme_minimal()


#The code creates a grouped bar chart illustrating the distribution of responses to the statement "Seminars encourage active participation 
#among students" across different education levels. Each bar represents an education level, and the colored segments within each bar indicate the 
#count of responses for various levels of agreement. The chart visually captures how perceptions of seminar effectiveness vary among education levels.