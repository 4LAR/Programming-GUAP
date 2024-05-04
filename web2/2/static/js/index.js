
// 7
// Объединение столбцов
// Определений (теги dl, dt, dd)


const news = [
  {
    "image": "https://kotlinlang.org/_next/static/chunks/images/news-0-42c4d2d8fbe0d41935e2d75788405214.png",
    "date": "March 12, 2024",
    "name": "The Ktor Roadmap for 2024",
    "body": "As in 2023 and 2022, we have been working on a roadmap for our development of Ktor for the year ahead. In the interests of transparency and accountability, we would like to share our plans with you here. Our ongoing plan Our ongoing plans and goals for Ktor remain consistent with previous years. We aim […]"
  },
  {
    "image": "https://kotlinlang.org/_next/static/chunks/images/news-1-696720f30c5699f4e60a127cd416f375.png",
    "date": "February 29, 2024",
    "name": "Compose Multiplatform 1.6.0 – Resources, UI Testing, iOS Accessibility, and Preview Annotation",
    "body": "Compose Multiplatform is a declarative UI framework built by JetBrains that allows developers to share UI implementations across different platforms. The 1.6.0 release brings several powerful features, as well as compatibility with the latest Kotlin version and changes from Google’s latest Jetpack Compose update. Get Started with Compose Multiplatform This release of Compose Multiplatform: For […]"
  },
  {
    "image": "https://kotlinlang.org/_next/static/chunks/images/news-2-728494e5ff1caccc572bbb6aa696c482.png",
    "date": "February 27, 2024",
    "name": "Become a Kotlin Google Summer of Code Contributor: Make an Impact!",
    "body": "The Kotlin Foundation has been accepted as a mentor organization for Google Summer of Code 2024!  GSoC is a global online program focused on bringing new contributors into open-source software development. Contributors work on a 12-week programming project under the guidance of Kotlin Foundation mentors from Google, Gradle, and JetBrains. What does this mean for […]"
  },
  {
    "image": "https://kotlinlang.org/_next/static/chunks/images/news-3-9019f27270b29ee6424563cabe50fe24.png",
    "date": "February 12, 2024",
    "name": "Amper Update – February 2024",
    "body": "Amper is an experimental project configuration tool by JetBrains. With the 0.2.0 release and its accompanying tooling, we have some exciting feature updates and highlights to share. Amper now supports Gradle version catalogs, completion for adding new dependencies, and more! Read on for more details. Gradle version catalogs To make it easier to add Amper […]"
  }
];

function fill_news() {
  for (const item of news) {
    append_to_ul("news", `
      <img src="${item.image}">
      <p class="date">${item.date}</p>
      <p class="name">${item.name}</p>
      <p class="body">${item.body}</p>
    `)
  }
}

// fill_news();
