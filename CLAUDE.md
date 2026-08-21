# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Purpose

A personal learning repository covering LLM fundamentals, RAG systems, fine-tuning, and autonomous agents. Almost all content is Jupyter notebooks. There is no test suite or build pipeline.

## Environment Setup

The primary dependency manifest is `4_LLM_Engineering/pyproject.toml` (Python ≥ 3.11). Install with `uv`:

```bash
cd 4_LLM_Engineering
uv sync
```

Or with pip from `requirements.txt`:

```bash
pip install -r 4_LLM_Engineering/requirements.txt
```

API keys are loaded via `python-dotenv`. Create a `.env` file at the root of `4_LLM_Engineering/` with keys for the providers you need (e.g. `OPENAI_API_KEY`, `ANTHROPIC_API_KEY`, `GOOGLE_API_KEY`).

For local models, install [Ollama](https://ollama.com) separately:

```bash
ollama run llama3.2       # 3B — standard
ollama run llama3.2:1b    # 1B — lightweight
```

## Running Notebooks

```bash
jupyter notebook                          # launch from any directory
jupyter notebook 1_MyNotebooks/1_LLM/1_Basics.ipynb   # open specific notebook
```

## Repository Structure

The numbered prefix on directories reflects the learning progression:

| Directory | Content |
|-----------|---------|
| `1_MyNotebooks/` | Personal consolidated notes: LLM basics, RAG, Agents, Projects |
| `3_Generative_AI/` | 19-module GenAI/ChatGPT/Copilot business course |
| `4_LLM_Engineering/` | 8-week bootcamp (900+ notebooks) — has its own `pyproject.toml` and `requirements.txt` |
| `6_AI_Agents/` | Agent framework courses: AutoGen, Crew.ai, Google/Kaggle, HuggingFace |
| `7_Claude/` | Claude Code learning notebook |
| `AI-First-Project/` | Standalone project notebooks |

### `4_LLM_Engineering/` Week Progression

`week1` → web scraping & summarization  
`week2` → Gradio UI & chatbots  
`week3` → HuggingFace pipelines, tokenizers, open-source models  
`week4` → model evaluation & code generation  
`week5` → RAG (chunking, retrieval, testing)  
`week6` → fine-tuning closed-source LLMs (OpenAI)  
`week7` → fine-tuning open-source models (QLoRA/LoRA/PEFT)  
`week8` → autonomous agent AI  

`guides/` contains 14 foundational notebooks (CLI, Git, Python, async, Docker/Terraform, etc.).  
`community-contributions/` holds notebooks from 40+ external contributors — treat as read-only reference material.

## Key Technologies

- **LLM APIs**: OpenAI, Anthropic (Claude), Google Gemini
- **Open-source models**: LLaMA, Mistral, via HuggingFace Transformers
- **Fine-tuning**: QLoRA, LoRA, PEFT, OpenAI Fine-tuning API
- **RAG**: LangChain, ChromaDB, Pinecone, FAISS, sentence-transformers
- **Agents**: AutoGen, Crew.ai, custom tool-calling agents
- **UI**: Gradio, Streamlit
- **Cloud**: Modal (serverless GPU), Google Colab
