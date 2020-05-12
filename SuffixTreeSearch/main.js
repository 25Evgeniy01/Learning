window.onload = () => {
	let input = document.querySelector('#input');
	let list = document.querySelectorAll('.ul li');
	let t = new GeneralizedSuffixTree();

	for (let i = 0; i < list.length; i++) {
		t.put(list[i].innerText, i)
	}
	input.oninput = function() {
		let value = this.value.trim();
		list = document.querySelectorAll('.ul li');

		let t0 = performance.now();
		if (value) {
			var r = t.search(value,-1);
			list.forEach((elem, i) => {
				(r && r[i]) ?
					elem.classList.remove('hide') :
					elem.classList.add('hide')
			});
		} else {
			list.forEach(elem => {
				elem.classList.remove('hide');
			});
		}
		let t1 = performance.now();

		let t01 = performance.now();
		value
			? list.forEach(elem => {
					elem.innerText.search(value) == -1
						? elem.classList.add('hide')
						: elem.classList.remove('hide');
			  })
			: list.forEach(elem => {
					elem.classList.remove('hide');
			  });
		let t11 = performance.now();
		console.log({
			tree: t1 - t0,
			search: t11 - t01
		});
	};
};
