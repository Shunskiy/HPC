function firstTask() {
  let answer = document.querySelector(".task__result--first");

  let Ghz = +document.getElementById("cpu-flops").value;
  let cpuCores = +document.getElementById("cpu-cores").value;
  let cpuYear = +document.getElementById("cpu-year").value;
  let result;

  switch (cpuYear) {
    case 1:
      result = Ghz * cpuCores * 4;
      break;
    case 2:
      result = Ghz * cpuCores * 8;
      break;
    case 3:
      result = Ghz * cpuCores * 16;
      break;
    default:
      break;
  }

  answer.innerHTML = result;

  console.log({ answer, Ghz, cpuCores, cpuYear, result });
}

function firstTaskMobile() {
  let answer = document.querySelector(".task__result--first-mobile");

  let Ghz = +document.getElementById("mobile-flops").value;
  let cpuCores = +document.getElementById("mobile-cores").value;

  let result = Ghz * cpuCores * 2 * 2;

  answer.innerHTML = result;

  console.log({ answer, Ghz, cpuCores, cpuYear, result });
}
