# load required libraries
library(ggplot2)
library(readxl)
library(dplyr)

# load dataset
dataset <- read_xlsx(
    path = "17-Influence of Webinars and Seminars on Students’ Academic Performance.xlsx"
)

# clean dataset
event <- select(
    dataset,
    "What is your current level of education?",
    "Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]",
    "Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]",
    "Technology & Interaction [The ability to review content later is a significant advantage of webinars.]",
    "Technology & Interaction [Webinars offer face-to-face discussions with instructors.]",
    "Technology & Interaction [Webinars provide ample opportunities for students to ask questions.]"
)

# drop NAs
event <- na.omit(event)

# metadata
dim(event)
summary(event)


likertLevels <- c(
    "Strongly disagree",
    "Disagree",
    "Neutral",
    "Agree",
    "Strongly agree"
)

event$`Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]` <- as.numeric(
    factor(
        event$`Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]`,
        levels = likertLevels
    )
)

likertRatio <- (max(
    event$`Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]`
) - min (
    event$`Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]`
))/length(unique(
    event$`Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]`
))

# plot 1
ggplot(
    data = event,
    aes(
        x = as.numeric(`Technology & Interaction [Interactive features like polls and quizzes enhance the value of webinars for students.]`),
        y = as.numeric(factor(`What is your current level of education?`)),
    )
) + geom_point(

) + labs(
    title = "Interactive features like polls and quizzes enhance the value of webinars for students",
    y = "Educational Qualification",
    x = "Responses",
    color = "Response Levels"
) + theme_light()

# sapply(event[2], mean)

event$`Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]` <- as.numeric(
    factor(
        event$`Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]`,
        levels = likertLevels
    )
)

factor(event$`Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]`)

# plot 2
ggplot(
    data = event,
    aes(
        x = factor(`Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]`),
        y = `Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]`
    )
) + geom_boxplot(

) + labs(
    title = "title",
    y = "y",
    x = "x"
) + theme_minimal()

# plot 3
event %>% ggplot(
    aes(
        x = `Technology & Interaction [The ability to review content later is a significant advantage of webinars.]`,
        fill = `Technology & Interaction [The ability to review content later is a significant advantage of webinars.]`
    )
) + geom_bar(
    position = "dodge",
    width = 0.7
) + facet_wrap(
    ~`What is your current level of education?`,
    scales = "free"
) + labs(
    y = "Response Count",
    x = "",
    fill = "Response Likert Scale",
    title = "Ability to review content later in Webinars is advantageous"
) + theme_minimal(

) + theme(
    legend.position = "bottom"
) + scale_fill_brewer(
    palette = "Set2"
)

# plot 4
event %>% ggplot(
    aes(
        x = factor(`What is your current level of education?`),
        y = `Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]`,
    )
) + geom_boxplot(
    fill = "khaki",
    color = "black"
) + labs(
    title = "Box and Whisker Plot",
    x = "Educational Level",
    y = "Likert Response"
) + theme_minimal()

# plot 5
event %>%
    ggplot(
        aes(
            x = factor(`Technology & Interaction [Real-time feedback in seminars is more effective than in webinars.]`),
        )
) + geom_histogram(
    stat = "bin",
    fill     = "seagreen",
    color    = "white",
    alpha    = 0.75
) + labs(
    title    = "Distribution of Likert Responses",
    x        = "Likert Response",
    y        = "Frequency/Density"
) + theme_minimal()
