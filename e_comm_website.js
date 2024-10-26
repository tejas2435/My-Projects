
    document.addEventListener('DOMContentLoaded', function() {
        // Get logo image element
        const logoImg = document.querySelector('.logo_img');
        // Get name element
        const nameElement = document.querySelector('.name');

        // Add click event listener to logo image
        logoImg.addEventListener('click', scrollToHome);
        // Add click event listener to name element
        nameElement.addEventListener('click', scrollToHome);

        // Function to scroll to the home section
        function scrollToHome(event) {
            event.preventDefault(); // Prevent default link behavior
            const homeSection = document.getElementById('home'); // Get the home section
            if (homeSection) {
                // Calculate offset to consider fixed header height
                const headerHeight = document.querySelector('header').offsetHeight;
                const targetOffset = homeSection.offsetTop - headerHeight;

                // Scroll to the home section smoothly
                window.scrollTo({
                    top: targetOffset,
                    behavior: 'smooth'
                });
            }
        }

        // Function to handle smooth scrolling to sections
        function scrollToSection(event) {
            event.preventDefault(); // Prevent default anchor behavior
            const targetId = this.getAttribute('href'); // Get the target section id
            const targetSection = document.querySelector(targetId); // Get the target section
            if (targetSection) {
                // Calculate offset to consider fixed header height
                const headerHeight = document.querySelector('header').offsetHeight;
                const targetOffset = targetSection.offsetTop - headerHeight;

                // Scroll to the target section smoothly
                window.scrollTo({
                    top: targetOffset,
                    behavior: 'smooth'
                });
            }
        }

        // Get all navigation links and footer links
        const navLinks = document.querySelectorAll('.nav_link');
        const footerLinks = document.querySelectorAll('.footer_link');

        // Add click event listeners to navigation links
        navLinks.forEach(link => {
            link.addEventListener('click', scrollToSection);
        });

        // Add click event listeners to footer links
        footerLinks.forEach(link => {
            link.addEventListener('click', scrollToSection);
        });
    });