import streamlit as st
import pandas as pd
import plotly.express as px
import time

# Set page configuration
st.set_page_config(page_title="NIT Kurukshetra Info App", layout="wide")

# Title with animation
st.title("🏛️ NIT Kurukshetra Information Portal")
st.markdown("---")

# Sidebar navigation
st.sidebar.header("Navigation")
page = st.sidebar.radio("Go to", ["About NIT Kurukshetra", "Departments", "Campus Life", "Admissions", "Contact Info", "Gallery", "Feedback"])

# About Section
if page == "About NIT Kurukshetra":
    st.header("🎓 About NIT Kurukshetra")
    st.write("NIT Kurukshetra is one of the premier engineering institutes in India, known for its excellence in technical education and research.")
    st.image("https://ugcounselor-content.s3.ap-south-1.amazonaws.com/wp-content/uploads/2024/04/03203527/NIT-Kurukshetra.jpg", caption="NIT Kurukshetra Campus", use_container_width=True)
    st.success("🏆 Ranked among the top NITs in India")

# Departments Section
departments = {
    "Computer Science and Engineering": "AI, ML, Cybersecurity, Data Science",
    "Electronics and Communication Engineering": "VLSI, Signal Processing, IoT",
    "Mechanical Engineering": "Thermal, Design, Manufacturing",
    "Civil Engineering": "Structural, Transportation, Environmental",
    "Electrical Engineering": "Power Systems, Control Systems",
    "Information Technology": "Software Development, Web Technologies"
}

if page == "Departments":
    st.header("🏛️ Departments at NIT Kurukshetra")
    dept = st.selectbox("Select a Department", list(departments.keys()))
    st.write(f"### {dept}")
    st.write(f"**Research Areas:** {departments[dept]}")
    st.balloons()

# Campus Life Section
if page == "Campus Life":
    st.header("🏕️ Campus Life at NIT Kurukshetra")
    st.write("NIT Kurukshetra offers a vibrant campus life with multiple clubs, fests, and sports facilities.")
    st.image("https://ugcounselor-content.s3.ap-south-1.amazonaws.com/wp-content/uploads/2024/04/03203527/NIT-Kurukshetra.jpg", caption="Campus Fest", use_container_width=True)
    clubs = ["Coding Club", "Robotics Club", "Music and Dance Society", "Sports Club", "Entrepreneurship Cell"]
    st.write("### Active Clubs:")
    st.write(", ".join(clubs))
    
    # Poll on favorite club
    club_choice = st.radio("Which club interests you the most?", clubs)
    if st.button("Vote"):
        st.success(f"Thank you for voting for {club_choice}!")

# Admissions Section
if page == "Admissions":
    st.header("📌 Admissions at NIT Kurukshetra")
    st.write("Admissions to undergraduate programs are through JEE Mains, and postgraduate admissions are based on GATE and other entrance exams.")
    st.info("For more details, visit the [official website](https://www.nitkkr.ac.in).")
    
    # Eligibility check widget
    jee_score = st.slider("Enter your JEE Main Score", 0, 360, 150)
    if jee_score >= 180:
        st.success("🎉 You have a good chance of getting into NIT Kurukshetra!")
    else:
        st.warning("📉 You may need to improve your score to secure admission.")

# Gallery Section
if page == "Gallery":
    st.header("📸 Campus Gallery")
    images = [
        "https://ugcounselor-content.s3.ap-south-1.amazonaws.com/wp-content/uploads/2024/04/03203527/NIT-Kurukshetra.jpg",
        "https://ugcounselor-content.s3.ap-south-1.amazonaws.com/wp-content/uploads/2024/04/03203527/NIT-Kurukshetra.jpg",
        "https://ugcounselor-content.s3.ap-south-1.amazonaws.com/wp-content/uploads/2024/04/03203527/NIT-Kurukshetra.jpg"
    ]
    for img in images:
        st.image(img, use_container_width=True)

# Contact Info Section
if page == "Contact Info":
    st.header("📞 Contact Information")
    st.write("**Address:** NIT Kurukshetra, Haryana, India")
    st.write("**Phone:** +91 1744 238122")
    st.write("**Email:** info@nitkkr.ac.in")
    st.map(pd.DataFrame({"lat": [29.9457], "lon": [76.8233]}), zoom=12)

# Feedback Section
if page == "Feedback":
    st.header("📝 Your Feedback Matters!")
    name = st.text_input("Your Name")
    feedback = st.text_area("Write your feedback here...")
    if st.button("Submit Feedback"):
        st.success("✅ Thank you for your valuable feedback!")
        time.sleep(1)
        st.experimental_rerun()

# Footer
st.markdown("---")
st.caption("Developed with ❤️ using Streamlit")